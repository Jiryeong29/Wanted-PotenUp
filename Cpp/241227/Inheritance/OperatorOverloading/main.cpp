#include <iostream>
#include "Vector2.h"
// 오버엔지니어링
//std::ostream& operator<<(std::ostream& os, const Vector2& vector)
//{
//	os << "(" << vector.GetX() << "," << vector.GetX() << ")\n";
//	return os;
//}
int main() 
{
	Vector2 postion(4.0f, 4.0f);
	Vector2 speed(0.5f, 0.5f);

	//Vector2 result = postion.Multiply(speed); // postion * speed
	Vector2 result = postion.operator*(speed); // *speed
	result[0];

	std::cout << postion << std::endl;
	std::cout << speed << std::endl;
	std::cout << result << "\n";

	std::cin.get();
}
