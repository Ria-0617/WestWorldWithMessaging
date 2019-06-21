//
//  WifesGlobalState.hpp
//  WestWorldWtihWoman
//
//  Created by 田中皓己 on 2019/06/18.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef WifesGlobalState_hpp
#define WifesGlobalState_hpp

#include <iostream>
#include <random>

#include "State.hpp"
#include "MinersWife.hpp"
#include "VisitBathroom.hpp"

class MinersWife;
class VisitBathroom;

class WifesGlobalState:public State<MinersWife>{
private:
    WifesGlobalState(){}
    
    WifesGlobalState(const WifesGlobalState&);
    WifesGlobalState& operator=(const WifesGlobalState&);
    
public:
    static WifesGlobalState* Instance();
    
    virtual void Enter(MinersWife* wife);
    virtual void Execute(MinersWife* wife);
    virtual void Exit(MinersWife* wife);
    
    float RandFloat(float min, float max);
};

#endif /* WifesGlobalState_hpp */
