//
//  DoHouseWork.cpp
//  WestWorldWtihWoman
//
//  Created by 田中皓己 on 2019/06/18.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#include "DoHouseWork.hpp"

using namespace std;

DoHouseWork* DoHouseWork::Instance(){
    static DoHouseWork instance;
    
    return &instance;
}


void DoHouseWork::Enter(MinersWife* wife){
    
}


void DoHouseWork::Execute(MinersWife* wife){
    switch(RandInt(0,2)){
        case 0:
            cout << GetNameOfEntity(wife->ID()) << ": Moppin' the floor" << endl;
            break;
            
        case 1:
            cout << GetNameOfEntity(wife->ID()) << ": Washin' the dishes" << endl;
            break;
            
        case 2:
            cout << GetNameOfEntity(wife->ID()) << ": Makin' the bed" << endl;
            break;
    }
}

void DoHouseWork::Exit(MinersWife* wife){
    
}

int DoHouseWork::RandInt(int min, int max){
    random_device seed_gen;
    default_random_engine engine(seed_gen());
    // min以上max以下の値を等確率で発生させる
    uniform_int_distribution<> dist(min, max);
    return dist(engine);
}
