//
//  MessageTypes.hpp
//  WestWorldWithMessaging
//
//  Created by 田中皓己 on 2019/06/21.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef MessageTypes_hpp
#define MessageTypes_hpp

#include <iostream>

enum message_type{
    Msg_HiHoneyImHome,
    Msg_StewReady
};

inline std::string MsgToStr(int msg)
{
    switch (msg)
    {
        case Msg_HiHoneyImHome:
            
            return "HiHoneyImHome";
            
        case Msg_StewReady:
            
            return "StewReady";
            
        default:
            
            return "Not recognized!";
    }
}


#endif /* MessageTypes_hpp */
