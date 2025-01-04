#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

class Player {
public:
	// Ŭ���� �̸��� �Ȱ��� ���� ������
	Player() 
		: x(0), y(0), speed(1)
	{
		std::cout << "������ ȣ�� \n";
	}
	// �Ҹ���
	~Player() 
	{
		std::cout << "�Ҹ��� ȣ��\n";
	}

	//�̵��� ��ŭ�� ���� �Է� �޾Ƽ� ��ǥ�� �̵���Ű�� �Լ�.
	void Move(int x, int y)
	{
		this->x += x;
		this->y += y; //�������̱� ������ ȭ��ǥ �����ڷ� �ۼ��ؾ� �Ѵ�. ->(�ַο� ������) �ڹٳ� c#�� ȥ���� ����� �ֱ⶧���� .���� �ٲ�
	}
private:
	// �ڹٶ� c#�� ������ ���� �γ� cpp�� ������ ���� �Ʒ��� �д�.
	int x;
	int y;
	int speed;
};

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(158);
	
	
	// ��ü / ��ü / ������Ʈ/ �ν��Ͻ�
	//Player player(); // ����� ȣ��
	//Player player; // �Ϲ��� ȣ��
	Player player = Player(); // �� 3���� ȣ��, ����Բ����� �̰��� ��ȣ��.
	player.Move(10, 20);


	// �������� �Ҵ�
	Player* player2 = new Player();
	//delete player2;
	//player2 = nullptr; // delete�� ���൵ �Ǵµ� �̷��Ա��� ���ִ� ���� �� ���� �����̴�. �̷��� ��Ȯ�ϰ� �������ָ�. ���߿�  null�� �ʱ�ȭ�� �ȴ�. �߰��߰� �Ҵ��ߴ� �������Ҷ� null�� �� �ʿ��ϴ� �׷��� �ƿ� ������ ���̴� ���� ����.

	std::cin.get();

}