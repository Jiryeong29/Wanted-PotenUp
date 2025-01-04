#include <iostream>

void q1() {
	int sum = 0;
	for (int i = 2; i <= 100; i+=2) {
		sum += i;
	}
	std::cout << sum << std::endl;
}
void q2() {

	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j < i ; j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}
void printReverse(const char* message)
{
	size_t len = strlen(message);

	for (int i = len-1; i >= 0; --i) {
		std::cout << message[i];
	}
	std::cout << std::endl;
}

void q3(int &a, int & b) {
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int a = 10, b = 20;
	//q1();
	//q2();
	//q3(a, b);
	
	printReverse("helloworld"); 
}