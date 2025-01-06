#include<iostream>

class Resource
{
public:
    Resource()
    {
        std::cout << "생성자 호출\n";
    }

    ~Resource()
    {
        std::cout << "소멸자 호출\n";
    }

    void Use()
    {
        std::cout << "자원 사용\n";
    }
};

int main() {
    
    std::shared_ptr<Resource> resource1 = std::make_shared<Resource>();
    {
        std::shared_ptr<Resource> resource2 = resource1;
        std::cout << "사용 횟수 : " << resource1.use_count() << "\n";
    }

    std::cout << "사용횟수 : " << resource1.use_count() << "\n";
}