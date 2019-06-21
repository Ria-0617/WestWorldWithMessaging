//
//  VisitBathroom.hpp
//  WestWorldWtihWoman
//
//  Created by 田中皓己 on 2019/06/18.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef VisitBathroom_hpp
#define VisitBathroom_hpp

#include <iostream>

#include "EntityNames.hpp"
#include "State.hpp"
#include "MinersWife.hpp"

class MinersWife;

class VisitBathroom:public State<MinersWife>{
private:
    VisitBathroom(){}
    
    VisitBathroom(const VisitBathroom&);
    VisitBathroom& operator=(const VisitBathroom&);
    
public:
    static VisitBathroom* Instance();
    
    virtual void Enter(MinersWife* wife);
    virtual void Execute(MinersWife* wife);
    virtual void Exit(MinersWife* wife);
};

#endif /* VisitBathroom_hpp */
