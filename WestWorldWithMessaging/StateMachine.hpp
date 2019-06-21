//
//  StateMachine.hpp
//  WestWorldWtihWoman
//
//  Created by 田中皓己 on 2019/05/30.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef StateMachine_hpp
#define StateMachine_hpp

#include <iostream>
#include <cassert>
#include <string>

#include "State.hpp"

template <class entity_type>
class StateMachine {
private:
    // このインスタンスを所有するエージェントへのポインタ
    entity_type* m_pOwner;
    
    State<entity_type>* m_pCurrentState;
    
    // エージェントの直前のステートを記録
    State<entity_type>* m_pPreviousState;
    
    // このステートロジックは、FSMあが更新されるたびに呼ばれる
    State<entity_type>* m_pGlobalState;
    
public:
    StateMachine(entity_type* owner):m_pOwner(owner),
                                     m_pCurrentState(NULL),
                                     m_pPreviousState(NULL),
                                     m_pGlobalState(NULL)
    {}
    
    virtual ~StateMachine(){}
    
    // FSMを初期化するときにこのメソッドを使う
    void SetCurrentState(State<entity_type>* s){m_pCurrentState = s;}
    void SetPreviousState(State<entity_type>* s){m_pPreviousState = s;}
    void SetGlobalState(State<entity_type>* s){m_pGlobalState = s;}
    
    // FSMを更新するときにこれを呼ぶ
    void Update()const{
        // グローバルステートがあるなら、そのメソッドを実行する
        if(m_pGlobalState) m_pGlobalState->Execute(m_pOwner);
        
        // 現在のステートと同じ
        if(m_pCurrentState) m_pCurrentState->Execute(m_pOwner);
    }
    
    // 新しいステートに変更
    void ChangeState(State<entity_type>* pNewState){
        assert(pNewState && "<StateMachine::ChangeState>: trying to change to NULL state");
        
        // 以前のステートを記録する
        m_pPreviousState = m_pCurrentState;
        
        // 存在するステートの終了メソッドを呼ぶ
        m_pCurrentState->Exit(m_pOwner);
        
        // 新しいステートに変更
        m_pCurrentState = pNewState;
        
        // 新しいステートの開始メソッドを呼ぶ
        m_pCurrentState->Enter(m_pOwner);
    }
    
    void RevertToPreviousState(){
        ChangeState(m_pPreviousState);
    }
    
    // アクセサ
    State<entity_type>* CurrentState()const{return m_pCurrentState;}
    State<entity_type>* PreviousState()const{return m_pPreviousState;}
    State<entity_type>* GlobalState()const{return m_pGlobalState;}
    
    // 現在のステートの型とパラメータで渡されたクラスの型が同じならtureを返す
    bool isInState(const State<entity_type>& st)const{
        return typeid(*m_pCurrentState) == typeid(st);
    }
};

#endif /* StateMachine_hpp */
