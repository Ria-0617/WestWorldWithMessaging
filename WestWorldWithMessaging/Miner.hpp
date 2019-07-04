//
//  Miner.hpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/23.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef Miner_hpp
#define Miner_hpp

#include <iostream>
#include <cassert>
#include "BaseGameEntity.hpp"
#include "Locations.hpp"
#include "State.hpp"
#include "StateMachine.hpp"
#include "Telegram.hpp"

#include "GoHomeAndSleepTilRested.hpp"

//the amount of gold a miner must have before he feels comfortable
const int ComfortLevel       = 5;
//the amount of nuggets a miner can carry
const int MaxNuggets         = 3;
//above this value a miner is thirsty
const int ThirstLevel        = 5;
//above this value a miner is sleepy
const int TirednessThreshold = 5;

class Miner : public BaseGameEntity {
private:
    
    // ステートマシンクラスのインスタンス
    StateMachine<Miner>* m_pStateMachine;
    
    // 鉱夫がが現在いる場所
    location_type m_Location;
    
    // 鉱夫がポケットに持っている金塊の数
    int m_iGoldCarried;
    
    // 鉱夫が銀行に預けている金額
    int m_iMoneyInBank;
    
    // この値が高いほど、鉱夫の喉が乾く
    int m_iThirst;
    
    // この値が高いほど、鉱夫は疲れる
    int m_iFatigue;
    
public:
    
    Miner(int id);
    ~Miner();
    
    void Update();
    
    virtual bool HandleMessage(const Telegram& msg);
    
    location_type Location()const{return m_Location;}
    void          ChangeLocation(const location_type loc){m_Location=loc;}
    
    int           GoldCarried()const{return m_iGoldCarried;}
    void          SetGoldCarried(const int val){m_iGoldCarried = val;}
    void          AddToGoldCarried(const int val);
    bool          PocketsFull()const{return m_iGoldCarried >= MaxNuggets;}
    
    bool          Fatigued()const;
    void          DecreaseFatigue(){m_iFatigue -= 1;}
    void          IncreaseFatigue(){m_iFatigue += 1;}
    
    int           Wealth()const{return m_iMoneyInBank;}
    void          SetWealth(const int val){m_iMoneyInBank = val;}
    void          AddToWealth(const int val);
    
    bool          Thirsty()const;
    void          BuyAndDrinkAWhiskey(){m_iThirst = 0; m_iMoneyInBank-=2;}
    
    
    StateMachine<Miner>* GetFSM()const{return m_pStateMachine;}
    
};

#endif /* Miner_hpp */
