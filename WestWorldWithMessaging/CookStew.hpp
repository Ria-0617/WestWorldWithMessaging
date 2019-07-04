//
//  CookStew.hpp
//  WestWorldWithMessaging
//
//  Created by 田中皓己 on 2019/07/05.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef CookStew_hpp
#define CookStew_hpp

#include <iostream>

#include "State.hpp"
#include "Telegram.hpp"
#include "MessageDispatcher.hpp"

#include "MinersWife.hpp"
#include "DoHouseWork.hpp"

class MinersWife;

class CookStew : public State<MinersWife> {
private:
    CookStew(){}
    
    CookStew(const CookStew&);
    CookStew& operator=(const CookStew&);
    
public:
    static CookStew* Instance();
    
    virtual void Enter(MinersWife* wife);
    virtual void Execute(MinersWife* wife);
    virtual void Exit(MinersWife* wife);
    
    virtual bool OnMessage(MinersWife* wife, const Telegram& msg);
};

#endif /* CookStew_hpp */
