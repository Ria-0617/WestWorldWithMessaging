//
//  WifesGlobalState.cpp
//  WestWorldWtihWoman
//
//  Created by 田中皓己 on 2019/06/18.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#include "WifesGlobalState.hpp"

using namespace std;

WifesGlobalState* WifesGlobalState::Instance(){
    static WifesGlobalState instance;
    
    return  &instance;
}

void WifesGlobalState::Enter(MinersWife *wife){
    
}

void WifesGlobalState::Execute(MinersWife *wife){
    if(RandFloat(0.0f,1.0f)<0.1f){
        wife->GetFSM()->ChangeState(VisitBathroom::Instance());
    }
}

void WifesGlobalState::Exit(MinersWife *wife){
    
}

float WifesGlobalState::RandFloat(float min, float max){
    random_device seed_gen;
    default_random_engine engine(seed_gen());
    // min以上max未満の値を等確率で発生させる
    uniform_real_distribution<> dist(min, max);
    return dist(engine);
}
