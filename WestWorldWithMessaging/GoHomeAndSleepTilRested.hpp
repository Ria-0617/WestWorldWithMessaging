//
//  GoHomeAndSleepTilRested.hpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/26.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef GoHomeAndSleepTilRested_hpp
#define GoHomeAndSleepTilRested_hpp

#include <iostream>

#include "State.hpp"
#include "Miner.hpp"
#include "Locations.hpp"
#include "EntityNames.hpp"

#include "EnterMineAndDigForNugget.hpp"

class Miner;

class EnterMineAndDigForNugget;

class GoHomeAndSleepTilRested : public State<Miner> {
private:
    
    GoHomeAndSleepTilRested(){}
    
    //copy ctor and assignment should be private
    GoHomeAndSleepTilRested(const GoHomeAndSleepTilRested&);
    GoHomeAndSleepTilRested& operator=(const GoHomeAndSleepTilRested&);
    
public:
    
    //this is a singleton
    static GoHomeAndSleepTilRested* Instance();
    
    virtual void Enter(Miner* miner);
    virtual void Execute(Miner* miner);
    virtual void Exit(Miner* miner);
};

#endif /* GoHomeAndSleepTilRested_hpp */
