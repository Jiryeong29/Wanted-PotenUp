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
	// 클래스 이름과 똑같이 생긴 생성자
	Player() 
		: x(0), y(0), speed(1)
	{
		std::cout << "생성자 호출 \n";
	}
	// 소멸자
	~Player() 
	{
		std::cout << "소멸자 호출\n";
	}

	//이동할 만큼의 양을 입력 받아서 좌표를 이동시키는 함수.
	void Move(int x, int y)
	{
		this->x += x;
		this->y += y; //포인터이기 때문에 화살표 연산자로 작성해야 한다. ->(애로우 연산자) 자바나 c#은 혼동의 우려가 있기때문에 .으로 바꿈
	}
private:
	// 자바랑 c#은 변수를 위에 두나 cpp은 변수를 보통 아래에 둔다.
	int x;
	int y;
	int speed;
};

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(158);
	
	
	// 객체 / 객체 / 오브젝트/ 인스턴스
	//Player player(); // 명시적 호출
	//Player player; // 암묵적 호출
	Player player = Player(); // 총 3가지 호출, 강사님께서는 이것을 선호합.
	player.Move(10, 20);


	// 동적으로 할당
	Player* player2 = new Player();
	//delete player2;
	//player2 = nullptr; // delete만 해줘도 되는데 이렇게까지 해주는 것이 더 좋은 습관이다. 이렇게 명확하게 지정해주면. 나중에  null로 초기화가 된다. 중간중간 할당했다 지웠다할때 null이 꼭 필요하다 그래서 아예 습관을 들이는 것이 좋다.

	std::cin.get();

}