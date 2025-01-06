#include<iostream>

class Resource
{
public:
    Resource()
    {
        std::cout << "������ ȣ��\n";
    }

    ~Resource()
    {
        std::cout << "�Ҹ��� ȣ��\n";
    }

    void Use()
    {
        std::cout << "�ڿ� ���\n";
    }
};

int main() {
    
    std::shared_ptr<Resource> resource1 = std::make_shared<Resource>();
    {
        std::shared_ptr<Resource> resource2 = resource1;
        std::cout << "��� Ƚ�� : " << resource1.use_count() << "\n";
    }

    std::cout << "���Ƚ�� : " << resource1.use_count() << "\n";
}