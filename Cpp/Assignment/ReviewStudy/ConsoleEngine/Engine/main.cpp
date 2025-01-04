#include <iostream>
#include <windows.h>

int main()
{
	double lastTime = GetCurrentTime();
	while (1)
	{
		double current = GetCurrentTime();
		double elapsed = (current - lastTime)/1000;

		std::cout << elapsed << std::endl;

	}
}