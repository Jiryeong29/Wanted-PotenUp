#include "TestLevel.h"
#include "Engine/Engine.h"
#include "Actor/Player.h"
#include "Actor/PlayerBullet.h"
#include "Actor/Enemy.h"
#include "Actor/EnemyBullet.h"

#include "Engine/Timer.h"
#include <Windows.h>
#include "time.h"
#include "string"
//
//struct EnemyType
//{
//    EnemyType(const char* image, const char* bylletImage, int score);
//
//    char* image = nullptr;
//    char* bulletImage = nullptr;
//    int score = 0;
//};
// 적 캐릭터 종류
static const char* enemyType[]
{

    "■",
    "▲",
    "●"
};

TestLevel::TestLevel()
   
{
    //player = new Player("<A>");
    player = new Player(" @@ \n@^^@\n @@ \n");
    AddActor(player);

}

TestLevel::~TestLevel()
{
}

void TestLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);
    //timer.Update(deltaTime);
	//예외 처리
	if (deltaTime > 1.0f)
	{
		return;
	}


	// ESC 키로 종료
	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}
    //char time[20];
    //sprintf_s(time, sizeof(time), "%.2f", timer.getElapsedTime());
    //Engine::Get().Draw(timePosition, time, Color::Green);


    //// 점수 출력.
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
    ////    (int)Color::Green);
    //Log("Score: %d", score);
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
    //     (int)Color::white);

    // 적 생성.
	SpawnEnemy(deltaTime);

    // 플레이어 탄약과 적의 충돌 처리.
    ProcessCollisionPlayerBulletAndEnemy();
    ProcessCollisionPlayerAndEnemy();
    
    // 플레잉어와 적 탄약의 충돌처리.
    ProcessCollisionPlayerAndEnemyBullet();
}

void TestLevel::Draw()
{
    // 테두리 그리기
    MapDraw();

    // 액터 그리기
    for (Actor* actor : actors)
    {
        actor->Draw();
    }

    Vector2 timePosition(3, Engine::Get().ScreenSize().y - 1);
    char scores[10];
    sprintf_s(scores, sizeof(scores), "%d", score);
    char* sco = scores;
    Engine::Get().Draw(timePosition, sco, Color::Blue);
}

void TestLevel::ProcessCollisionPlayerAndEnemy() {
    // 탄약 및 적 캐릭터 배열 선언.
    List<Enemy*> enemies;

    // 레벨에 배치된 액터를 순회하면서 리스트 채우기.
    for (Actor* actor : actors)
    {
        // 적으로 형변환 후 확인해서 리스트 채우기.
        Enemy* enemy = actor->As<Enemy>();
        if (enemy)
        {
            enemies.PushBack(enemy);
        }
    }

    // 예외 처리.
    if (enemies.Size() == 0)
    {
        return;
    } 
    
    
    for (Enemy* enemy : enemies)
    {
        // 적이 비활성화 상태라면 건너뛰기.
        if (!enemy->IsAcive())
        {
            continue;
        }

        // 충돌 처리.
        if (enemy->aabb(*player))
        {
            // 충돌했으면 적 제거.
            enemy->Destroy();


            const char* playerDeath = " @@ \n@TT@\n @@ \n";

            Vector2 currentPlayer(player->Position().x, player->Position().y);

            Engine::Get().Draw(currentPlayer, playerDeath, Color::Green);




            player->Destroy();

            // 약 2초간 정지.
            //Sleep(1000);

            // 게임 종료.
            //Engine::Get().QuitGame();
        }
    }
}
void TestLevel::MapDraw()
{
   
}
void TestLevel::SpawnEnemy(float deltaTime)
{
    // 적 생성.
    static float elapsedTime = 0.0f;
    static float spawnTime = RandomPercent(1.0f, 3.0f);

    // 타이머.
    elapsedTime += deltaTime;

    if (elapsedTime < spawnTime)
    {
        return;
    }

    // 타이머 리셋.
    elapsedTime = 0.0f;
    spawnTime = RandomPercent(1.0f, 3.0f);


    // 적 생성.
    static int length = sizeof(enemyType) / sizeof(enemyType[0]);
    //static int length = _countof(enemyType);
    int index = Random(0, length - 1);

    AddActor(new Enemy(enemyType[index]));
    AddActor(new Enemy(enemyType[index]));
}

void TestLevel::ProcessCollisionPlayerBulletAndEnemy()
{
    // 탄약 및 적 캐릭터 배열 선언.
    List<PlayerBullet*> bullets;
    List<Enemy*> enemies;

    // 레벨에 배치된 액터를 순회하면서 리스트 채우기.
    for (Actor* actor : actors)
    {
        // 탄약으로 형변환 후 확인해서 리스트 채우기.
        PlayerBullet* bullet = actor->As<PlayerBullet>();
        if (bullet)
        {
            bullets.PushBack(bullet);
            continue;
        }

        // 적으로 형변환 후 확인해서 리스트 채우기.
        Enemy* enemy = actor->As<Enemy>();
        if (enemy)
        {
            enemies.PushBack(enemy);
        }
    }

    // 예외 처리.
    if (bullets.Size() == 0 || enemies.Size() == 0)
    {
        return;
    }

    // 두 배열을 순회하면서 충돌 처리.
    for (PlayerBullet* bullet : bullets)
    {
        for (Enemy* enemy : enemies)
        {
            // 적이 비활성화 상태라면 건너뛰기.
            if (!enemy->IsAcive())
            {
                continue;
            }

            // 충돌 처리.
            if (enemy->aabb(*bullet))
            {
                // 충돌했으면 적 제거.
                enemy->Destroy();

                // 탄약도 제거.
                bullet->Destroy();

                // 점수 추가.
                score += 100;
            }
        }
    }
}

void TestLevel::ProcessCollisionPlayerAndEnemyBullet()
{
    // 플레이어와 적 탄약 변수 선언.
    Player* player = nullptr;
    List<EnemyBullet*> bullets;

    // 레벨에 배치된 액터를 순회하면서 리스트 채우기.
    for (Actor* actor : actors)
    {
        // 플레이어 검색.
        if (!player)
        {
            player = actor->As<Player>();
            continue;
        }

        // 탄약으로 형변환 후 확인해서 리스트 채우기.
        EnemyBullet* bullet = actor->As<EnemyBullet>();
        if (bullet)
        {
            bullets.PushBack(bullet);
            continue;
        }
    }

    // 예외처리.
    if (player == nullptr || bullets.Size() == 0)
    {
        return;
    }

    // 배열 순회하면서 충돌 처리.
    for (EnemyBullet* bullet : bullets)
    {
        // 탄약과 플레이어가 충돌했는지 확인.
        if (player->aabb(*bullet))
        {
            // 플레이어 제거
            player->Destroy();

            int y = Engine::Get().ScreenSize().y;

            // 약 2초간 정지.
            Sleep(2000);

            // 게임 종료.
            Engine::Get().QuitGame();
        }
    }


}
