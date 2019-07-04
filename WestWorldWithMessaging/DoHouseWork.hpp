//
//  DoHouseWork.hpp
//  WestWorldWtihWoman
//
//  Created by 田中皓己 on 2019/06/18.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef DoHouseWork_hpp
#define DoHouseWork_hpp

#include <iostream>
#include <random>

#include "EntityNames.hpp"
#include "State.hpp"
#include "MinersWife.hpp"
#include "Telegram.hpp"

class MinersWife;

class DoHouseWork:public State<MinersWife>{
private:
    DoHouseWork(){}
    
    DoHouseWork(const DoHouseWork&);
    DoHouseWork& operator=(const DoHouseWork&);
    
public:
    static DoHouseWork* Instance();
    
    virtual void Enter(MinersWife* wife);
    virtual void Execute(MinersWife* wife);
    virtual void Exit(MinersWife* wife);
    
    virtual bool OnMessage(MinersWife* wife, const Telegram& msg);
    
    int RandInt(int min, int max);
};

#endif /* DoHouseWork_hpp */
