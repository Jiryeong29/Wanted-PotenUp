// 헤더 포함
#include "Entity.h"

// 헤더포함
#include "Entity.h"
#include <iostream>

Entity::Entity(): x(0),y(0)
{
	std::cout << "Entity() called\n";
}

Entity::~Entity()
{
	std::cout << "~Entity() called\n";
}

void Entity::Move(int xAmount, int yAmount)
{
}
