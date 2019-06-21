//
//  EnterMineAndDigForNugget.cpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/26.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#include "EnterMineAndDigForNugget.hpp"

using namespace std;

EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance(){
    static EnterMineAndDigForNugget instance;
    
    return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner* pMiner){
    if(pMiner->Location() != goldmine){
        cout << GetNameOfEntity(pMiner->ID()) << ": " << "Walkin' to the gold mine" << endl;
        
        pMiner->ChangeLocation(goldmine);
    }
}

void EnterMineAndDigForNugget::Execute(Miner* pMiner){
    // 鉱夫がMaxNuggetsを超える金塊を運べるようになるまで金を掘る
    // 鉱夫が掘っている間に喉の渇きを覚えたら、作業を止めてステートを変更し、
    // ウイスキーを飲みに酒場へ行く
    
    pMiner->AddToGoldCarried(1);
    
    // 金塊を掘るのは辛い仕事だ
    pMiner->IncreaseFatigue();
    
    cout << GetNameOfEntity(pMiner->ID()) << ": " << "Pickin' up a nugget" << endl;;
    
    // 十分金を掘ったら、銀行に行って預ける
    if(pMiner->PocketsFull()){
        pMiner->GetFSM()->ChangeState(VisitBankAndDepositGold::Instance());
    }
    
    // 喉が渇いたらウイスキーを飲みに行く
    if(pMiner->Thirsty()){
        pMiner->GetFSM()->ChangeState(QuenchThirst::Instance());
    }
}

void EnterMineAndDigForNugget::Exit(Miner *pMiner){
    cout << GetNameOfEntity(pMiner->ID()) << ": " << "Ah'm leavin' the gold mine with mah pokets full o' sweet gold" << endl;
}
