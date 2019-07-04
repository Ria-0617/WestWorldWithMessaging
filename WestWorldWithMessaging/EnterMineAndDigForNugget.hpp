//
//  EnterMineAndDigForNugget.hpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/26.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef EnterMineAndDigForNugget_hpp
#define EnterMineAndDigForNugget_hpp

#include <iostream>

#include "State.hpp"
#include "Miner.hpp"
#include "Locations.hpp"
#include "EntityNames.hpp"
#include "Telegram.hpp"

#include "VisitBankAndDepositGold.hpp"
#include "QuenchThirst.hpp"

class Miner;
class VisitBankAndDepositGold;
class QuenchThirst;

class EnterMineAndDigForNugget : public State<Miner> {
private:
    EnterMineAndDigForNugget(){}
    
    //copy ctor and assignment should be private
    EnterMineAndDigForNugget(const EnterMineAndDigForNugget&);
    EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget&);
    
public:
    // これがシングルトン
    static EnterMineAndDigForNugget* Instance();
    
    virtual void Enter(Miner* pMiner);
    virtual void Execute(Miner* pMiner);
    virtual void Exit(Miner* pMiner);
    
    virtual bool OnMessage(Miner* pMiner, const Telegram& msg);
};

#endif /* EnterMineAndDigForNugget_hpp */
