//
//  QuenchThirst.cpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/26.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#include "QuenchThirst.hpp"

using namespace std;

QuenchThirst* QuenchThirst::Instance(){
    static QuenchThirst instance;
    
    return &instance;
}

void QuenchThirst::Enter(Miner* pMiner){
    if (pMiner->Location() != saloon)
    {
        pMiner->ChangeLocation(saloon);
        
        cout << GetNameOfEntity(pMiner->ID()) << ": " << "Boy, ah sure is thusty! Walking to the saloon" << endl;
    }
}

void QuenchThirst::Execute(Miner* pMiner){
    if (pMiner->Thirsty())
    {
        pMiner->BuyAndDrinkAWhiskey();
        
        cout << GetNameOfEntity(pMiner->ID()) << ": " << "That's mighty fine sippin liquer" << endl;
        
        pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
    }else{
        cout << "\nERROR!\nERROR!\nERROR!";
    }
}

void QuenchThirst::Exit(Miner* pMiner)
{
    cout << GetNameOfEntity(pMiner->ID()) << ": " << "Leaving the saloon, feelin' good" << endl;
}

bool QuenchThirst::OnMessage(Miner *pMiner, const Telegram &msg){
    return false;
}
