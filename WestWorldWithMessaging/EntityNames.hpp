//
//  EntityName.hpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/23.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef EntityName_hpp
#define EntityName_hpp

#include <string>

enum
{
    ent_Miner_Bob,
    ent_Elsa
};

inline std::string GetNameOfEntity(int n) {
    switch(n) {
        case ent_Miner_Bob:
            return "Miner Bob";
            
        case ent_Elsa:
            return "Elsa";
            
        default:
            return "UNKNOWN!";
    }
}

#endif /* EntityName_hpp */
