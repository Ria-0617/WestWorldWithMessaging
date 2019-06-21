//
//  State.hpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/23.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

template <class entity_type>
class State{
public:
    virtual ~State(){}
    
    virtual void Enter(entity_type*) = 0;
    virtual void Execute(entity_type*) = 0;
    virtual void Exit(entity_type*) = 0;
};

#endif /* State_hpp */
