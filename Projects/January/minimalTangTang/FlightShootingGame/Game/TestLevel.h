#pragma once

#include "Level/Level.h"

class Player;
class Timer;
class TestLevel : public Level
{
	// RTTI ����.
	RTTI_DECLARATIONS(TestLevel, Level)
public:
	TestLevel();
	~TestLevel();

	virtual void Update(float deltaTime) override;
	virtual void Draw() override;
private:

	// �� ���� �Լ�.
	void SpawnEnemy(float deltaTime);

	// �÷��̾� ź��� ���� �浹 ó��.
	void ProcessCollisionPlayerBulletAndEnemy(); 
	// �� ź��� �÷��̾���� �浹 ó��.
	void ProcessCollisionPlayerAndEnemyBullet(); 

	// �ۼ��� : ������
	// �÷��̾�� �� �浹 ó��
	void ProcessCollisionPlayerAndEnemy();
	void MapDraw();
private:
	//����.
	int score = 0;
	Player* player = nullptr;
	//Timer timer;

};