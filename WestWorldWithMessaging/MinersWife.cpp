//
//  MinersWife.cpp
//  WestWorldWtihWoman
//
//  Created by 田中皓己 on 2019/06/18.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#include "MinersWife.hpp"

MinersWife::MinersWife(int id):BaseGameEntity(id),
                               m_Location(shack),
                               m_bCooking(false)
{
    m_pStateMachine = new StateMachine<MinersWife>(this);
    
    m_pStateMachine->SetCurrentState(DoHouseWork::Instance());
    
    m_pStateMachine->SetGlobalState(WifesGlobalState::Instance());
}

MinersWife::~MinersWife(){
    delete m_pStateMachine;
}

void MinersWife::Update()
{
    m_pStateMachine->Update();
}


bool MinersWife::HandleMessage(const Telegram& msg){
    return m_pStateMachine->HandleMessage(msg);
}
