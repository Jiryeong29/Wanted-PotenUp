#include "PreCompiledHeader.h"
#include "Level.h"
#include "Actor/Actor.h"
//#include <iostream>

Level::Level()
{
}

Level::~Level()
{
    //메모리 해제
    //for (int ix = 0; ix < actors.Size(); ++ix)
    //{
    //    //액터 삭제
    //    delete actors[ix];
    //}

    // 메모리 해제.
    for (Actor* actor : actors)
    {
        delete actor;
    }

    //동적 배열 해제
    //delete[] actors;
}

void Level::AddActor(Actor* newActor)
{
    // actors.PushBack(newActor);
    addRequestedActor = newActor;
}

void Level::ProcessAddedAndDestroyedActor()
{
    // 액터 순회 후 삭제 요청된 액터를 처리.
    for (int ix = 0; ix < actors.Size();)
    {
        if (actors[ix]->isExpired)
        {
            delete actors[ix];
            actors[ix] = nullptr;
            actors.Erase(ix);
            continue;
        }
        ++ix;
    }
    // 추가 요청된 액터 처리.
    if (addRequestedActor)
    {
        actors.PushBack(addRequestedActor);
        addRequestedActor = nullptr;
    }
}


void Level::Update(float deltaTime)
{
    for ( Actor* actor : actors)
    {
        if (!actor->isActive || actor->isExpired)
        {
            continue;
        }
        actor->Update(deltaTime);
    }
}

void Level::Draw()
{
    for (Actor* actor : actors)
    {
        if (!actor->isActive || actor->isExpired)
        {
            continue;
        }
        actor->Draw();
    }
}

