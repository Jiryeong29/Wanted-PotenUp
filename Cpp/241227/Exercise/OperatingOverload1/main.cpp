#include "Vector2.h"

int main() {
	Vector2 position1 = Vector2(4.0f, 3.0f);
	Vector2 position2 = Vector2(2.0f, 1.0f);
	Vector2 direction = position1 - position2;
	std::cout << direction << std::endl;
	//direction.display();
}
