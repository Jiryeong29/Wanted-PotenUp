#include "Entity.h" // #include <Entity.h> ���� ��	
#include "Player.h"
#include <iostream>

int main() {

	// Entity  ��ü ����.
	Entity* entity = new Entity();

	// Player ��ü ����.
	Player* player = new Player("Ronnie");
	
	// ������
	Entity* entity2 = player;

	delete entity;
	delete player;

	std::cin.get();
}