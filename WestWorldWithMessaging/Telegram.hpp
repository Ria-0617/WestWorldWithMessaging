//
//  Telegram.hpp
//  WestWorldWithMessaging
//
//  Created by 田中皓己 on 2019/06/21.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef Telegram_hpp
#define Telegram_hpp

#include <iostream>
#include <math.h>

struct Telegram{
    // このTelegramを送ったエンティティ
    int sender;
    
    // このTelegramを受け取るエンティティ
    int receiver;
    
    // メッセージそのもの。MessegeType.hに列挙されているもの全て
    int Msg;
    
    // メッセージは直ちに送信されるか、特定の時間だけ遅らせることができる
    // 遅らせる必要がある場合は、このフィールドはメッセージが送信される時間が書かれている
    double dispatchTime;
    
    // メッセージに添えられる追加情報
    void* extraInfo;
    
    Telegram():dispatchTime(-1),
    sender(-1),
    receiver(-1),
    Msg(-1) {}
    
    Telegram(double time, int    sender, int    receiver, int    msg, void*  info = NULL):
    dispatchTime(time),
    sender(sender),
    receiver(receiver),
    Msg(msg),
    extraInfo(info) {}
};

//these telegrams will be stored in a priority queue. Therefore the >
//operator needs to be overloaded so that the PQ can sort the telegrams
//by time priority. Note how the times must be smaller than
//SmallestDelay apart before two Telegrams are considered unique.
const double SmallestDelay = 0.25;


inline bool operator==(const Telegram& t1, const Telegram& t2)
{
    return ( fabs(t1.dispatchTime-t2.dispatchTime) < SmallestDelay) &&
    (t1.sender == t2.sender)        &&
    (t1.receiver == t2.receiver)    &&
    (t1.Msg == t2.Msg);
}

inline bool operator<(const Telegram& t1, const Telegram& t2)
{
    if (t1 == t2)
    {
        return false;
    }
    
    else
    {
        return  (t1.dispatchTime < t2.dispatchTime);
    }
}

inline std::ostream& operator<<(std::ostream& os, const Telegram& t)
{
    os << "time: " << t.dispatchTime << "  Sender: " << t.sender
    << "   Receiver: " << t.receiver << "   Msg: " << t.Msg;
    
    return os;
}

//handy helper function for dereferencing the ExtraInfo field of the Telegram
//to the required type.
template <class T>
inline T DereferenceToType(void* p)
{
    return *(T*)(p);
}

#endif /* Telegram_hpp */
