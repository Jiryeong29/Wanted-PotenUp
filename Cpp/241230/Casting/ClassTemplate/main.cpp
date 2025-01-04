#include <iostream>

template<typename T>
class Data
{
public:
	Data(T newData)
		: data(newData)
	{
	}
	void setData(T newData)
	{
		data = newData;
	}
	T GetData() const { return data;}
private:
	T data;
};

int main()
{
	Data<int> data(10);
	Data<float> pi(3.141592f);

	std::cout << data.GetData() << std::endl;
	std::cout << pi.GetData() << std::endl;
	
	std::cin.get();
}