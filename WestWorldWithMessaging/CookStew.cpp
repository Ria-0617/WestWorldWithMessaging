//
//  CookStew.cpp
//  WestWorldWithMessaging
//
//  Created by 田中皓己 on 2019/07/05.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#include "CookStew.hpp"

using namespace std;

CookStew* CookStew::Instance()
{
    static CookStew instance;
    
    return &instance;
}

void CookStew::Enter(MinersWife* wife){
    if(!wife->Cooking()){
        cout << GetNameOfEntity(wife->ID()) << ": Putting the stew in the oven" << endl;
        
        Dispatch->DispatchMessage(1.5,                          // 遅延時間
                                  wife->ID(),                   // 送信者ID
                                  wife->ID(),                   // 受信者ID
                                  Msg_StewReady,                // メッセージ
                                  (void*)NO_ADDITIONAL_INFO);   // 追加情報なし
        wife->SetCooking(true);
    }
}

void CookStew::Execute(MinersWife* wife)
{
    cout << GetNameOfEntity(wife->ID()) << ": Fussin' over food" << endl;
}

void CookStew::Exit(MinersWife* wife)
{
    cout << GetNameOfEntity(wife->ID()) << ": Puttin' the stew on the table" << endl;
}

bool CookStew::OnMessage(MinersWife *wife, const Telegram &msg){
    switch (msg.Msg) {
        case Msg_StewReady:
            cout << "Message received by " << GetNameOfEntity(wife->ID()) <<" at time: " << Clock->GetCurrentTime() << endl;
            cout << GetNameOfEntity(wife->ID()) << ": StewReady! Lets eat" << endl;
            
            // 夫にシチューの準備ができたことを知らせる
            Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
                                      wife->ID(),
                                      ent_Miner_Bob,
                                      Msg_StewReady,
                                      (void*)NO_ADDITIONAL_INFO);
            wife->SetCooking(false);
            
            wife->GetFSM()->ChangeState(DoHouseWork::Instance());
            
            return true;
            break;
    }
    return false;
}
