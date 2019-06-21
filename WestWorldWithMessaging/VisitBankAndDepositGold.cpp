//
//  VisitBankAndDepositGold.cpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/26.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#include "VisitBankAndDepositGold.hpp"

using namespace std;

VisitBankAndDepositGold* VisitBankAndDepositGold::Instance(){
    static VisitBankAndDepositGold instance;
    
    return &instance;
}


void VisitBankAndDepositGold::Enter(Miner* pMiner){
    //on entry the miner makes sure he is located at the bank
    if (pMiner->Location() != bank){
        cout << GetNameOfEntity(pMiner->ID()) << ": " << "Goin' to the bank. Yes siree" << endl;
        
        pMiner->ChangeLocation(bank);
    }
}


void VisitBankAndDepositGold::Execute(Miner* pMiner){
    
    //deposit the gold
    pMiner->AddToWealth(pMiner->GoldCarried());
    
    pMiner->SetGoldCarried(0);
    
    cout << GetNameOfEntity(pMiner->ID()) << ": " << "Depositing gold. Total savings now: "<< pMiner->Wealth() << endl;
    
    //wealthy enough to have a well earned rest?
    if (pMiner->Wealth() >= ComfortLevel){
        cout << GetNameOfEntity(pMiner->ID()) << ": " << "WooHoo! Rich enough for now. Back home to mah li'lle lady" << endl;
        
        pMiner->GetFSM()->ChangeState(GoHomeAndSleepTilRested::Instance());
    }
    //otherwise get more gold
    else{
        pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
    }
}


void VisitBankAndDepositGold::Exit(Miner* pMiner){
    cout << GetNameOfEntity(pMiner->ID()) << ": " << "Leavin' the bank" << endl;
}

