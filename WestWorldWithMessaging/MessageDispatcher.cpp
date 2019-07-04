//
//  MessageDispatcher.cpp
//  WestWorldWithMessaging
//
//  Created by 田中皓己 on 2019/06/23.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#include "MessageDispatcher.hpp"

using namespace std;

MessageDispatcher* MessageDispatcher::Instance(){
    static MessageDispatcher instance;
    
    return  &instance;
}

void MessageDispatcher::Discharge(BaseGameEntity *pReceiver, const Telegram &telegram){
    if(!pReceiver->HandleMessage(telegram)){
        //telegram could not be handled
        cout << "Message not handled" << endl;
    }
}

void MessageDispatcher::DispatchMessage(double delay, int sender, int receiver, int msg, void *ExtraInfo = NULL){
    // メッセージ送信者と受信者のポインタを作る
    BaseGameEntity* pSender = EntityMgr->GetEntityFromID(sender);
    BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(receiver);
    
    // make sure the receiver is valid
    if (pReceiver == NULL)
    {
        cout << "Warning! No Receiver with ID of " << receiver << " found" << endl;
        
        return;
    }
    // Telegramをす作成する
    Telegram telegram(0,sender,receiver,msg,ExtraInfo);
    
    // 遅らせる必要がないなら、直ちにTelegramを送る
    if (delay <= 0.0) {
        cout << "Instant telegram dispatched at time: " << Clock->GetCurrentTime()
        << " by " << GetNameOfEntity(pSender->ID()) << " for " << GetNameOfEntity(pReceiver->ID())
        << ". Msg is "<< MsgToStr(msg) << endl;
        
        // 受信者にTelegramを送る
        Discharge(pReceiver, telegram);
    }
    // 遅らせる必要があるならTelegramが送信される時間を計算する
    else{
        double currentTime = Clock->GetCurrentTime();
        telegram.dispatchTime = currentTime + delay;
        
        // キューにTelegramを置く
        priorityQ.insert(telegram);
    }
}

void MessageDispatcher::DispatchDelayedMessages(){
    // 最初に現在の時刻を取得する
    double currentTime = Clock->GetCurrentTime();
    
    // ここでTelegramが送信を必要としているかどうかを調べるためにキューを見る
    // 賞味期限を過ぎたキューのTelegramを全て先頭から削除する
    while (!priorityQ.empty() &&
           (priorityQ.begin()->dispatchTime < currentTime) &&
           (priorityQ.begin()->dispatchTime > 0)) {
        // キューの先頭からTelegramを読む
        const Telegram& telegram = *priorityQ.begin();
        
        // 受信者を見つける
        BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(telegram.receiver);
        
        cout << "Queued telegram ready for dispatch: Sent to "
        << GetNameOfEntity(pReceiver->ID()) << ". Msg is " << MsgToStr(telegram.Msg) << endl;
        
        // 受信者にTelegramを送る
        Discharge(pReceiver, telegram);
        
        // そしてキューから削除する
        priorityQ.erase(priorityQ.begin());
    }
}
