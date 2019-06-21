//
//  BaseGameEntity.hpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/23.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef BaseGameEntity_hpp
#define BaseGameEntity_hpp

#include <iostream>

class BaseGameEntity{
private:
    // どのエンティティも一意のIDを持つ
    int m_ID;
    
    // これは次の有効なID。BaseGameEntityがインスタンス化されるたびにこの値は更新される
    static int m_iNextValidID;
    
    // これはIDが正しく設定されたかを確認するためにコンストラクタの中で呼ばれる
    // これはIDを設定し次の有効なIDをインクリメントする前に、メソッドに渡された値が次の有効なID以上であるかを確認する
    void SetID(int val);
    
public:
    BaseGameEntity(int id) {
        SetID(id);
    }
    
    virtual ~BaseGameEntity(){}
    
    // 全てのエンティティは、Update関数を実装する必要がある
    virtual void Update() = 0;
    
    int ID()const { return m_ID; }
};

#endif /* BaseGameEntity_hpp */
