#pragma once

#include "Level/Level.h"

class Player;
class Timer;
class TestLevel : public Level
{
	// RTTI 적용.
	RTTI_DECLARATIONS(TestLevel, Level)
public:
	TestLevel();
	~TestLevel();

	virtual void Update(float deltaTime) override;
	virtual void Draw() override;
private:

	// 적 생성 함수.
	void SpawnEnemy(float deltaTime);

	// 플레이어 탄약과 적의 충돌 처리.
	void ProcessCollisionPlayerBulletAndEnemy(); 
	// 적 탄약과 플레이어어의 충돌 처리.
	void ProcessCollisionPlayerAndEnemyBullet(); 

	// 작성자 : 신지령
	// 플레이어와 적 충돌 처리
	void ProcessCollisionPlayerAndEnemy();
	void MapDraw();
private:
	//점수.
	int score = 0;
	Player* player = nullptr;
	//Timer timer;

};