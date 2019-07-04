//
//  EatStew.hpp
//  WestWorldWithMessaging
//
//  Created by 田中皓己 on 2019/07/05.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef EatStew_hpp
#define EatStew_hpp

#include <iostream>

#include "State.hpp"
#include "Miner.hpp"
#include "Locations.hpp"
#include "EntityNames.hpp"
#include "Telegram.hpp"

class Miner;

class EatStew : public State<Miner>{
private:
    EatStew(){}
    EatStew(const EatStew&);
    EatStew& operator=(const EatStew&);
    
public:
    static EatStew* Instance();
    
    virtual void Enter(Miner* miner);
    virtual void Execute(Miner* miner);
    virtual void Exit(Miner* miner);
    virtual bool OnMessage(Miner* agent, const Telegram& msg);
};

#endif /* EatStew_hpp */
