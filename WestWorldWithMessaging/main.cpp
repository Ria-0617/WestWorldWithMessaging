//
//  main.cpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/23.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#include <iostream>
#include "EntityNames.hpp"
#include "Miner.hpp"
#include "MinersWife.hpp"
#include "EntityManager.hpp"
#include "MessageDispatcher.hpp"


int main(int argc, const char * argv[]) {
    Miner* Bob = new Miner(ent_Miner_Bob);
    MinersWife* Elsa = new MinersWife(ent_Elsa);
    
    EntityMgr->RegisterEntity(Bob);
    EntityMgr->RegisterEntity(Elsa);
    
    for(int i=0; i<30; ++i){
        Bob->Update();
        Elsa->Update();
        
        Dispatch->DispatchDelayedMessages();
    }
    
    delete Bob;
    delete Elsa;
    
    return 0;
}
