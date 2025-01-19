#include "Bank.h"
#include "Account.h"
#include "CreditAccount.h"
#include "DonationAccount.h"
#include <iostream>
Bank::Bank()

    :   fout("customerInfo.txt", std::ios_base::out), // ������ append ���� ����  
        fin("customerInfo.txt", std::ios_base::in | std::ios_base::trunc),
        totalCustomers(0)
{
    if (fin.is_open() && fout.is_open())
    {
        std::cout << "������ �ҷ����� ���߽��ϴ�.\n";
    }

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

void Bank::CreateAccount(int accountType)
{
    // �� ���� 100���� �Ѿ��� ��
    if (totalCustomers > 100)
    {
        std::cout << "�ִ� ���� ���� ���� �����Ͽ� ���¸� ������ �� �����ϴ�." << std::endl;
        return;
    }

    // �ӽ÷� �Է� ���� ������
    int id, balance;
    char name[100];
    
    // �� ���� �Է�
    std::cout << "���¸� �����ϰڽ��ϴ�. ������ �Է����ּ���." << std::endl;
    std::cout << "���� : "; std::cin >> id;
    std::cout << "�̸� : "; std::cin >> name;
    std::cout << "�ܾ� : "; std::cin >> balance;
    
    // �� ���� ����
    switch (accountType)
    {
    case 1: // �Ϲ� ����
        account[totalCustomers] = new Account(id, name, balance, "�Ϲݰ���");
        ++totalCustomers;
        break;
    case 2: // �ſ� ����
        account[totalCustomers] = new CreditAccount(id, name, balance, "�ſ����");
        ++totalCustomers;
        break;
    case 3 : // ��� ����
        account[totalCustomers] = new DonationAccount(id, name, balance, "��ΰ���");
        ++totalCustomers;
        break;
    default:
        break;
    }
}

bool Bank::findAccount(int AccountNumber)
{
    if (totalCustomers == 0)
    {
        std::cout << "������ ���°� �ϳ��� �����ϴ�...���¸� �������ּ���.." << std::endl;
        return false;
    }

    for (int i = 0; i < totalCustomers; ++i)
    {
        if (account[i]->getId() == AccountNumber)
        {
            std::cout << "�Ա��Ͻ÷��� ���¸� ã�ҽ��ϴ�\n";
            return true;
        }
    }

    std::cout << "�Ա��Ͻ÷��� ���¸� ã�� ���߽��ϴ�. �ٽ� �Է����ּ���\n";

    return false;
}
void Bank::Deposit()
{
    std::cout << "�Ա� �ݾװ� �Ա��Ͻ÷��� ���¹�ȣ�� �Է����ּ���." << std::endl;
    // �Է¹ޱ� ���� ������ ������
    int depositAmount;              // �Ա��� �ݾ�
    int depositAccountNumber;       // �Ա��� ���� ��ȣ
    std::cout << "�Ա� �ݾ� : "; std::cin >> depositAmount; 
    std::cout << "���� ��ȣ : "; std::cin >> depositAccountNumber;
    
    // ���°� ���� ��� ��� �Է� �ޱ�
    while (!(findAccount(depositAccountNumber)==true))
    {
        std::cout << "���� ���� ��ȣ�Դϴ�. �ٽ� �Է����ּ���." << std::endl;
        std::cout << "���� ��ȣ : "; std::cin >> depositAccountNumber;
    }

    // �Ա�
    account[depositAccountNumber]->deposit(depositAmount);
    

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
    account[accountNumber]->setBalance(account[accountNumber]->getBalance() - withdrawAmount);
}

void Bank::Inquire()
{
    std::cout << "��ü ���¸� ��ȸ�մϴ�." << std::endl;
    for (int i = 0; i < totalCustomers; ++i)
    {
        std::cout << "���� : " << account[i]->getId() << std::endl;
        std::cout << "�̸� : " << account[i]->getName() << std::endl;
        std::cout << "�ܾ� : " << account[i]->getBalance() << std::endl;
        
        account[i]->DonationInfo();
        std::cout << std::endl;
    }
}
