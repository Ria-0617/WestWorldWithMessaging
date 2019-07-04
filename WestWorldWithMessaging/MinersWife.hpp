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
#include "Telegram.hpp"

#include "DoHouseWork.hpp"
#include "WifesGlobalState.hpp"


class MinersWife:public BaseGameEntity{
private:
    StateMachine<MinersWife>* m_pStateMachine;
    
    location_type m_Location;
    
    bool m_bCooking;
    
public:
    
    MinersWife(int id);
    ~MinersWife();
    
    void Update();
    
    virtual bool HandleMessage(const Telegram& msg);
    
    StateMachine<MinersWife>* GetFSM()const{return m_pStateMachine;}
    
    //----------------------------------------------------accessors
    location_type Location()const{return m_Location;}
    void          ChangeLocation(const location_type loc){m_Location=loc;}
    
    bool          Cooking()const{return m_bCooking;}
    void          SetCooking(bool val){m_bCooking = val;}
    
};

#endif /* MinerWife_hpp */
