#include <iostream>
#include <stdlib.h>
int RandomRange(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}
int main()

{
	std::cout << RandomRange(4, 5) << '\n';

}