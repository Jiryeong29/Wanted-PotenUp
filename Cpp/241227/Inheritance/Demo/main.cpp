#include "Entity.h" // #include <Entity.h> 捞力 凳	
#include "Player.h"
#include <iostream>

int main() {

	// Entity  按眉 积己.
	Entity* entity = new Entity();

	// Player 按眉 积己.
	Player* player = new Player("Ronnie");
	
	// 促屈己
	Entity* entity2 = player;

	delete entity;
	delete player;

	std::cin.get();
}