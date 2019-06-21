//
//  QuenchThirst.hpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/26.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef QuenchThirst_hpp
#define QuenchThirst_hpp

#include <iostream>

#include "State.hpp"
#include "Miner.hpp"
#include "Locations.hpp"
#include "EntityNames.hpp"
#include "EnterMineAndDigForNugget.hpp"

class Miner;

class EnterMineAndDigForNugget;

class QuenchThirst : public State<Miner> {
private:
    
    QuenchThirst(){}
    
    //copy ctor and assignment should be private
    QuenchThirst(const QuenchThirst&);
    QuenchThirst& operator=(const QuenchThirst&);
    
public:
    
    //this is a singleton
    static QuenchThirst* Instance();
    
    virtual void Enter(Miner* miner);
    virtual void Execute(Miner* miner);
    virtual void Exit(Miner* miner);
};

#endif /* QuenchThirst_hpp */
