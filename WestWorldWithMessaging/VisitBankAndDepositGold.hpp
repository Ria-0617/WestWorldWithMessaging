//
//  VisitBankAndDepositGold.hpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/26.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef VisitBankAndDepositGold_hpp
#define VisitBankAndDepositGold_hpp

#include <iostream>

#include "State.hpp"
#include "Miner.hpp"
#include "Locations.hpp"
#include "EntityNames.hpp"

#include "EnterMineAndDigForNugget.hpp"
#include "GoHomeAndSleepTilRested.hpp"

class Miner;

class EnterMineAndDigForNugget;
class GoHomeAndSleepTilRested;

class VisitBankAndDepositGold : public State<Miner> {
private:
    VisitBankAndDepositGold(){}
    
    VisitBankAndDepositGold(const VisitBankAndDepositGold&);
    VisitBankAndDepositGold& operator=(const VisitBankAndDepositGold&);
    
public:
    static VisitBankAndDepositGold* Instance();
    
    virtual void Enter(Miner* miner);
    virtual void Execute(Miner* miner);
    virtual void Exit(Miner* miner);
};

#endif /* VisitBankAndDepositGold_hpp */
