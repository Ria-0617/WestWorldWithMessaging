//
//  MessageDispatcher.hpp
//  WestWorldWithMessaging
//
//  Created by 田中皓己 on 2019/06/23.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef MessageDispatcher_hpp
#define MessageDispatcher_hpp

#include <iostream>
#include <set>

#include "Telegram.hpp"
#include "BaseGameEntity.hpp"
#include "EntityManager.hpp"
#include "EntityNames.hpp"
#include "MessageTypes.hpp"

#include "CrudeTimer.h"

#define Dispatch MessageDispatcher::Instance()

//to make code easier to read
const double SEND_MSG_IMMEDIATELY = 0.0;
const int    NO_ADDITIONAL_INFO   = 0;

// メッセージの送信を管理するクラス
class MessageDispatcher{
private:
    // std::setは、遅延メッセージのコンテナとして使われる
    // これは、自動的にソーティングにより重複を避けるメソッドがあるからである
    // メッセージの送信時刻でソートされる
    std::set<Telegram> priorityQ;
    
    // このメソッドはDispatchMessageまたはDispatchDelayMessageによって利用される
    // このメソッドは、新たに作成されたTelegramとともに受け取り側のエンティティpReceiverのメッセージ処理用のメンバー関数を呼ぶ
    void Discharge(BaseGameEntity* pReceiver, const Telegram& telegram);
    
    MessageDispatcher(){}
    
    //copy ctor and assignment should be private
    MessageDispatcher(const MessageDispatcher&);
    MessageDispatcher& operator=(const MessageDispatcher&);
    
public:
    // このクラスはシングルトン
    static MessageDispatcher* Instance();
    
    // 他のエージェントにメッセージを送る
    void DispatchMessage(double delay, int sender, int receiver, int msg, void* ExtraInfo);
    
    // 遅延メッセージを送る。このメソッドは、メインゲームのループを回るたびに呼ばれる
    void DispatchDelayedMessages();
};

#endif /* MessageDispatcher_hpp */
