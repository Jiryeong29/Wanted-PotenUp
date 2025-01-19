#include "Bank.h"
#include "Account.h"
#include <iostream>
Bank::Bank()
    : totalCustomers(0)
{
}

Bank::~Bank()
{
    for (int i = 0; i < totalCustomers; ++i)
    {
        if (account[i] != nullptr)
        {
            delete account[i];
            account[i] = nullptr;
        }
    }
}

void Bank::CreateAccount()
{
    if (totalCustomers > 100)
    {
        std::cout << "�ִ� ���� ���� ���� �����Ͽ� ���¸� ������ �� �����ϴ�." << std::endl;
        return;
    }

    int id, balance;
    char name[100];
    
    // �� ���� �Է�
    std::cout << "���¸� �����ϰڽ��ϴ�. ������ �Է����ּ���." << std::endl;
    std::cout << "���� : "; std::cin >> id;
    std::cout << "�̸� : "; std::cin >> name;
    std::cout << "�ܾ� : "; std::cin >> balance;
    
    // �� ���� ����
    account[totalCustomers] = new Account(id, name, balance);
    ++totalCustomers;
}

int Bank::findAccount(int AccountNumber)
{
    if (totalCustomers == 0)
    {
        std::cout << "������ ���°� �ϳ��� �����ϴ�...���¸� �������ּ���.." << std::endl;
        return -1;
    }

    for (int i = 0; i < totalCustomers; ++i)
    {
        if (account[i]->getId() == AccountNumber)
        {
            return i;
        }
    }

    return -1;
}
void Bank::Deposit()
{
    std::cout << "�Ա� �ݾװ� �Ա��Ͻ÷��� ���¹�ȣ�� �Է����ּ���." << std::endl;
    int depositAmount;
    int depositAccountNumber;
    int accountNumber;
    std::cout << "�Ա� �ݾ� : "; std::cin >> depositAmount;
    std::cout << "���� ��ȣ : "; std::cin >> depositAccountNumber;
    
    // �Ա� ���� ã��
    accountNumber = findAccount(depositAccountNumber);
    while (accountNumber == -1)
    {
        std::cout << "���� ���� ��ȣ�Դϴ�. �ٽ� �Է����ּ���." << std::endl;
        std::cout << "���� ��ȣ : "; std::cin >> depositAccountNumber;
        accountNumber = findAccount(depositAccountNumber);
    }

    // �Ա�
    depositAmount = account[accountNumber]->getBalance() + depositAmount;
    account[accountNumber]->setBalance(depositAmount);


}
void Bank::WithDraw()
{
    std::cout << "��� �ݾװ� ����Ͻ÷��� ���¹�ȣ�� �Է����ּ���." << std::endl;
    int withdrawAmount;
    int withdrawAccountNumber;
    int accountNumber;
    std::cout << "��� �ݾ� : "; std::cin >> withdrawAmount;
    std::cout << "���� ��ȣ : "; std::cin >> withdrawAccountNumber;

    // ��� ���� ã��
    accountNumber = findAccount(withdrawAccountNumber);
    while (accountNumber == -1)
    {
        std::cout << "���� ���� ��ȣ�Դϴ�. �ٽ� �Է����ּ���." << std::endl;
        std::cout << "���� ��ȣ : "; std::cin >> withdrawAccountNumber;
        accountNumber = findAccount(withdrawAccountNumber);
    }

    // ���
    withdrawAmount = account[accountNumber]->getBalance()- withdrawAmount;
    account[accountNumber]->setBalance(withdrawAmount);
}

void Bank::Inquire()
{
    std::cout << "��ü ���¸� ��ȸ�մϴ�." << std::endl;
    for (int i = 0; i < totalCustomers; ++i)
    {
        std::cout << "���� : " << account[i]->getId() << std::endl;
        std::cout << "�̸� : " << account[i]->getName() << std::endl;
        std::cout << "�ܾ� : " << account[i]->getBalance() << std::endl<<std::endl;
    }
}
