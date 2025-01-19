#include "String.h"

int main() 
{
	String string("RonnieJ");

	std::cout << string << "\n";

	string = "Test String.";
	std::cout << string << "\n";
	std::cout << string.Length() << "\n";

	auto result = string == "RonnieJ" ? "True" : "False";  // False°¡ ³ª¿È ¹®ÀÚ¿­ÀÌ Test String. ÀÌ¶û ºñ±³µÊ
	std::cout << result << "\n";
	std::cout << ((string != "RonnieJ") ? "True" : "False") << "\n";
	
	std::cin.get();
}