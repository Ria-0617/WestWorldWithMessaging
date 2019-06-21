//
//  GoHomeAndSleepTilRested.cpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/26.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#include "GoHomeAndSleepTilRested.hpp"

using namespace std;

GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::Instance(){
    static GoHomeAndSleepTilRested instance;
    
    return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner* pMiner){
    if (pMiner->Location() != shack){
        cout << GetNameOfEntity(pMiner->ID()) << ": " << "Walkin' home" << endl;
        
        pMiner->ChangeLocation(shack);
    }
}

void GoHomeAndSleepTilRested::Execute(Miner* pMiner){
    //if miner is not fatigued start to dig for nuggets again.
    if (!pMiner->Fatigued()){
        cout << GetNameOfEntity(pMiner->ID()) << ": " << "What a God darn fantastic nap! Time to find more gold" << endl;
        
        pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
    }else{
        //sleep
        pMiner->DecreaseFatigue();
     
        cout << GetNameOfEntity(pMiner->ID()) << ": " << "ZZZZ... " << endl;
    }
}

void GoHomeAndSleepTilRested::Exit(Miner* pMiner){
    cout << GetNameOfEntity(pMiner->ID()) << ": " << "Leaving the house" << endl;
}
