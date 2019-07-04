//
//  EatStew.cpp
//  WestWorldWithMessaging
//
//  Created by 田中皓己 on 2019/07/05.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#include "EatStew.hpp"

using namespace std;

EatStew* EatStew::Instance()
{
    static EatStew instance;
    
    return &instance;
}


void EatStew::Enter(Miner* pMiner)
{
    cout << GetNameOfEntity(pMiner->ID()) << ": " << "Smells Reaaal goood Elsa!" << endl;
}

void EatStew::Execute(Miner* pMiner)
{
    cout << GetNameOfEntity(pMiner->ID()) << ": " << "Tastes real good too!" << endl;
    
    pMiner->GetFSM()->RevertToPreviousState();
}

void EatStew::Exit(Miner* pMiner)
{
    cout << GetNameOfEntity(pMiner->ID()) << ": " << "Thankya li'lle lady. Ah better get back to whatever ah wuz doin'" << endl;;
}


bool EatStew::OnMessage(Miner* pMiner, const Telegram& msg)
{
   return false;
}
