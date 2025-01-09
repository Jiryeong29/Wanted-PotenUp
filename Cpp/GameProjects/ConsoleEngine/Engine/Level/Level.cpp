#include "PreCompiledHeader.h"
#include "Level.h"
#include "Actor/Actor.h"
//#include <iostream>

Level::Level()
{
}

Level::~Level()
{
    //�޸� ����
    //for (int ix = 0; ix < actors.Size(); ++ix)
    //{
    //    //���� ����
    //    delete actors[ix];
    //}

    // �޸� ����.
    for (Actor* actor : actors)
    {
        delete actor;
    }

    //���� �迭 ����
    //delete[] actors;
}

void Level::AddActor(Actor* newActor)
{
    actors.PushBack(newActor);
}

void Level::DestroyActor()
{
    // ���� ��ȸ �� ���� ��û�� ���͸� ó��.
    for (int ix = 0; ix < actors.Size(); ++ix)
    {
        if (actors[ix]->isExpired)
        {
            delete actors[ix];
            actors[ix] = nullptr;
            actors.Erase(ix);
        }
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

