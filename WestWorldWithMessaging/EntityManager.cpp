//
//  EntityManager.cpp
//  WestWorldWithMessaging
//
//  Created by 田中皓己 on 2019/06/21.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#include "EntityManager.hpp"

EntityManager* EntityManager::Instance(){
    static EntityManager instance;
    
    return &instance;
}

BaseGameEntity* EntityManager::GetEntityFromID(int id)const
{
    //find the entity
    EntityMap::const_iterator ent = m_EntityMap.find(id);
    
    //assert that the entity is a member of the map
    assert ( (ent !=  m_EntityMap.end()) && "<EntityManager::GetEntityFromID>: invalid ID");
    
    return ent->second;
}

void EntityManager::RegisterEntity(BaseGameEntity* NewEntity)
{
    m_EntityMap.insert(std::make_pair(NewEntity->ID(), NewEntity));
}

void EntityManager::RemoveEntity(BaseGameEntity* pEntity)
{
    m_EntityMap.erase(m_EntityMap.find(pEntity->ID()));
}
