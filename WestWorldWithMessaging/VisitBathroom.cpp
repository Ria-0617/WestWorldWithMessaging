//
//  VisitBathroom.cpp
//  WestWorldWtihWoman
//
//  Created by 田中皓己 on 2019/06/18.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#include "VisitBathroom.hpp"
using namespace std;

VisitBathroom* VisitBathroom::Instance()
{
    static VisitBathroom instance;
    
    return &instance;
}


void VisitBathroom::Enter(MinersWife* wife)
{
    cout << GetNameOfEntity(wife->ID()) << ": Walkin' to the can. Need to powda mah pretty li'lle nose" << endl;
}


void VisitBathroom::Execute(MinersWife* wife)
{
    cout << GetNameOfEntity(wife->ID()) << ": Ahhhhhh! Sweet relief!" << endl;
    
    wife->GetFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(MinersWife* wife)
{
    cout << GetNameOfEntity(wife->ID()) << ": Leavin' the Jon" <<endl;
}

bool VisitBathroom::OnMessage(MinersWife *wife, const Telegram &msg){
    return false;
}
