#include <iostream>

class Calculator {
public:

	Calculator() :x(0) ,y(0), cntAdd(0), cntDiv(0), cntSub(0), cntMultiple(0){

	}
	int Add(int x, int y) 
	{
		cntAdd++;
		return x + y;
	}
	int Divide(int x, int y) 
	{
		cntDiv++;
		return x / y;
	}
	int Substract(int x, int y)
	{
		cntSub++;
		return x - y;
	}
	int Multiply(int x, int y)
	{
		cntMultiple++;
		return x * y;
	}

	void ShowOperationCount() {
		std::cout <<"µ¡¼À : " << cntAdd << std::endl;
		std::cout <<"³ª´°¼À : " << cntDiv << std::endl;
		std::cout <<"»¬¼À : " << cntSub << std::endl;
		std::cout <<"°ö¼À:  " << cntMultiple << std::endl;
	}
private:

	int cntAdd;
	int cntDiv;
	int cntSub;
	int cntMultiple;
};

int main()
{
	Calculator calculator;

	std::cout << "3+5=" << calculator.Add(3, 5) << "\n";
	std::cout << "3/5=" << calculator.Divide(3, 5) << "\n";
	std::cout << "12-7=" << calculator.Substract(12, 7) << "\n";
	std::cout << "12x7=" << calculator.Multiply(12, 7) << "\n";
	std::cout << "12x7=" << calculator.Multiply(12, 7) << "\n";
	std::cout << "12x7=" << calculator.Multiply(12, 7) << "\n";

	calculator.ShowOperationCount();
}