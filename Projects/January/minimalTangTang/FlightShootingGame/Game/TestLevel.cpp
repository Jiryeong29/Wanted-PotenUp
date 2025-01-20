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
// �� ĳ���� ����
static const char* enemyType[]
{

    "��",
    "��",
    "��"
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
	//���� ó��
	if (deltaTime > 1.0f)
	{
		return;
	}


	// ESC Ű�� ����
	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}
    //char time[20];
    //sprintf_s(time, sizeof(time), "%.2f", timer.getElapsedTime());
    //Engine::Get().Draw(timePosition, time, Color::Green);


    //// ���� ���.
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
    ////    (int)Color::Green);
    //Log("Score: %d", score);
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
    //     (int)Color::white);

    // �� ����.
	SpawnEnemy(deltaTime);

    // �÷��̾� ź��� ���� �浹 ó��.
    ProcessCollisionPlayerBulletAndEnemy();
    ProcessCollisionPlayerAndEnemy();
    
    // �÷��׾�� �� ź���� �浹ó��.
    ProcessCollisionPlayerAndEnemyBullet();
}

void TestLevel::Draw()
{
    // �׵θ� �׸���
    MapDraw();

    // ���� �׸���
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
    // ź�� �� �� ĳ���� �迭 ����.
    List<Enemy*> enemies;

    // ������ ��ġ�� ���͸� ��ȸ�ϸ鼭 ����Ʈ ä���.
    for (Actor* actor : actors)
    {
        // ������ ����ȯ �� Ȯ���ؼ� ����Ʈ ä���.
        Enemy* enemy = actor->As<Enemy>();
        if (enemy)
        {
            enemies.PushBack(enemy);
        }
    }

    // ���� ó��.
    if (enemies.Size() == 0)
    {
        return;
    } 
    
    
    for (Enemy* enemy : enemies)
    {
        // ���� ��Ȱ��ȭ ���¶�� �ǳʶٱ�.
        if (!enemy->IsAcive())
        {
            continue;
        }

        // �浹 ó��.
        if (enemy->aabb(*player))
        {
            // �浹������ �� ����.
            enemy->Destroy();


            const char* playerDeath = " @@ \n@TT@\n @@ \n";

            Vector2 currentPlayer(player->Position().x, player->Position().y);

            Engine::Get().Draw(currentPlayer, playerDeath, Color::Green);




            player->Destroy();

            // �� 2�ʰ� ����.
            //Sleep(1000);

            // ���� ����.
            //Engine::Get().QuitGame();
        }
    }
}
void TestLevel::MapDraw()
{
   
}
void TestLevel::SpawnEnemy(float deltaTime)
{
    // �� ����.
    static float elapsedTime = 0.0f;
    static float spawnTime = RandomPercent(1.0f, 3.0f);

    // Ÿ�̸�.
    elapsedTime += deltaTime;

    if (elapsedTime < spawnTime)
    {
        return;
    }

    // Ÿ�̸� ����.
    elapsedTime = 0.0f;
    spawnTime = RandomPercent(1.0f, 3.0f);


    // �� ����.
    static int length = sizeof(enemyType) / sizeof(enemyType[0]);
    //static int length = _countof(enemyType);
    int index = Random(0, length - 1);

    AddActor(new Enemy(enemyType[index]));
    AddActor(new Enemy(enemyType[index]));
}

void TestLevel::ProcessCollisionPlayerBulletAndEnemy()
{
    // ź�� �� �� ĳ���� �迭 ����.
    List<PlayerBullet*> bullets;
    List<Enemy*> enemies;

    // ������ ��ġ�� ���͸� ��ȸ�ϸ鼭 ����Ʈ ä���.
    for (Actor* actor : actors)
    {
        // ź������ ����ȯ �� Ȯ���ؼ� ����Ʈ ä���.
        PlayerBullet* bullet = actor->As<PlayerBullet>();
        if (bullet)
        {
            bullets.PushBack(bullet);
            continue;
        }

        // ������ ����ȯ �� Ȯ���ؼ� ����Ʈ ä���.
        Enemy* enemy = actor->As<Enemy>();
        if (enemy)
        {
            enemies.PushBack(enemy);
        }
    }

    // ���� ó��.
    if (bullets.Size() == 0 || enemies.Size() == 0)
    {
        return;
    }

    // �� �迭�� ��ȸ�ϸ鼭 �浹 ó��.
    for (PlayerBullet* bullet : bullets)
    {
        for (Enemy* enemy : enemies)
        {
            // ���� ��Ȱ��ȭ ���¶�� �ǳʶٱ�.
            if (!enemy->IsAcive())
            {
                continue;
            }

            // �浹 ó��.
            if (enemy->aabb(*bullet))
            {
                // �浹������ �� ����.
                enemy->Destroy();

                // ź�൵ ����.
                bullet->Destroy();

                // ���� �߰�.
                score += 100;
            }
        }
    }
}

void TestLevel::ProcessCollisionPlayerAndEnemyBullet()
{
    // �÷��̾�� �� ź�� ���� ����.
    Player* player = nullptr;
    List<EnemyBullet*> bullets;

    // ������ ��ġ�� ���͸� ��ȸ�ϸ鼭 ����Ʈ ä���.
    for (Actor* actor : actors)
    {
        // �÷��̾� �˻�.
        if (!player)
        {
            player = actor->As<Player>();
            continue;
        }

        // ź������ ����ȯ �� Ȯ���ؼ� ����Ʈ ä���.
        EnemyBullet* bullet = actor->As<EnemyBullet>();
        if (bullet)
        {
            bullets.PushBack(bullet);
            continue;
        }
    }

    // ����ó��.
    if (player == nullptr || bullets.Size() == 0)
    {
        return;
    }

    // �迭 ��ȸ�ϸ鼭 �浹 ó��.
    for (EnemyBullet* bullet : bullets)
    {
        // ź��� �÷��̾ �浹�ߴ��� Ȯ��.
        if (player->aabb(*bullet))
        {
            // �÷��̾� ����
            player->Destroy();

            int y = Engine::Get().ScreenSize().y;

            // �� 2�ʰ� ����.
            Sleep(2000);

            // ���� ����.
            Engine::Get().QuitGame();
        }
    }


}
