//
//  EntityManager.hpp
//  WestWorldWithMessaging
//
//  Created by 田中皓己 on 2019/06/21.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef EntityManager_hpp
#define EntityManager_hpp

#include <iostream>
#include <map>

#include "BaseGameEntity.hpp"

#define EntityMgr EntityManager::Instance()

class EntityManager{
private:
    // 入力を楽にするため
    typedef std::map<int, BaseGameEntity*> EntityMap;
    
    // エンティティがすぐに調べられるように、
    // この中ではエンティティへのポインタはそのIDで相互参照される
    EntityMap m_EntityMap;
    
    EntityManager(){}
    
    EntityManager(const EntityManager&);
    EntityManager& operator=(const EntityManager&);
    
public:
    static EntityManager* Instance();
    
    // パラメータとして与えられたIDを持つエンティティへのポインタを返す
    BaseGameEntity* GetEntityFromID(int id)const;
    
    // このメソッドはエンティティのIDで示されたインデックスの位置にある
    // std::vector m_Entites内のエンティティにポインタを格納する（アクセスをより早くするため）
    void RegisterEntity(BaseGameEntity* NewEntity);
    
    // このメソッドはリストからエンティティを削除する
    void RemoveEntity(BaseGameEntity* pEntity);
};

#endif /* EntityManager_hpp */
