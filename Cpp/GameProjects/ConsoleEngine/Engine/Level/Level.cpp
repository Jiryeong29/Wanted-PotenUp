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

void Level::Update(float deltaTime)
{
    //������ ���Ե� ���͸� ��ȸ�ϸ鼭 Update �Լ� ȣ��
    /*for (int ix = 0; ix < actors.Size();++ix)
    {
        actors[ix]->Update(deltaTime);
    }*/
    for ( Actor* actor : actors)
    {
        actor->Update(deltaTime);
    }
}

void Level::Draw()
{
    //������ ���Ե� ���͸� ��ȸ�ϸ鼭 Draw �Լ� ȣ��
    /*for (int ix = 0; ix < actors.Size();++ix)
    {
        actors[ix]->Draw();
    }*/
    for (Actor* actor : actors)
    {
        actor->Draw();
    }
}

