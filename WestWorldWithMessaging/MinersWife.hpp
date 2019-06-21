//
//  MinerWife.hpp
//  WestWorldWtihWoman
//
//  Created by 田中皓己 on 2019/06/18.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef MinerWife_hpp
#define MinerWife_hpp

#include <iostream>
#include "BaseGameEntity.hpp"
#include "Locations.hpp"
#include "State.hpp"
#include "StateMachine.hpp"

#include "DoHouseWork.hpp"
#include "WifesGlobalState.hpp"


class MinersWife:public BaseGameEntity{
private:
    StateMachine<MinersWife>* m_pStateMachine;
    
    location_type m_Location;
    
public:
    
    MinersWife(int id);
    ~MinersWife();
    
    void Update();
    
    StateMachine<MinersWife>* GetFSM()const{return m_pStateMachine;}
    
    //----------------------------------------------------accessors
    location_type Location()const{return m_Location;}
    void          ChangeLocation(const location_type loc){m_Location=loc;}
    
};

#endif /* MinerWife_hpp */
