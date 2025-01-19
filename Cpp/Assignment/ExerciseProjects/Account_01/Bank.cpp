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
        std::cout << "최대 계좌 개설 수에 도달하여 계좌를 개설할 수 없습니다." << std::endl;
        return;
    }

    int id, balance;
    char name[100];
    
    // 고객 계좌 입력
    std::cout << "계좌를 개설하겠습니다. 정보를 입력해주세요." << std::endl;
    std::cout << "계좌 : "; std::cin >> id;
    std::cout << "이름 : "; std::cin >> name;
    std::cout << "잔액 : "; std::cin >> balance;
    
    // 고객 계좌 생성
    account[totalCustomers] = new Account(id, name, balance);
    ++totalCustomers;
}

int Bank::findAccount(int AccountNumber)
{
    if (totalCustomers == 0)
    {
        std::cout << "개설된 계좌가 하나도 없습니다...계좌를 개설해주세요.." << std::endl;
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
    std::cout << "입금 금액과 입금하시려는 계좌번호를 입력해주세요." << std::endl;
    int depositAmount;
    int depositAccountNumber;
    int accountNumber;
    std::cout << "입금 금액 : "; std::cin >> depositAmount;
    std::cout << "계좌 번호 : "; std::cin >> depositAccountNumber;
    
    // 입금 계좌 찾기
    accountNumber = findAccount(depositAccountNumber);
    while (accountNumber == -1)
    {
        std::cout << "없는 계좌 번호입니다. 다시 입력해주세요." << std::endl;
        std::cout << "계좌 번호 : "; std::cin >> depositAccountNumber;
        accountNumber = findAccount(depositAccountNumber);
    }

    // 입금
    depositAmount = account[accountNumber]->getBalance() + depositAmount;
    account[accountNumber]->setBalance(depositAmount);


}
void Bank::WithDraw()
{
    std::cout << "출금 금액과 출금하시려는 계좌번호를 입력해주세요." << std::endl;
    int withdrawAmount;
    int withdrawAccountNumber;
    int accountNumber;
    std::cout << "출금 금액 : "; std::cin >> withdrawAmount;
    std::cout << "계좌 번호 : "; std::cin >> withdrawAccountNumber;

    // 출금 계좌 찾기
    accountNumber = findAccount(withdrawAccountNumber);
    while (accountNumber == -1)
    {
        std::cout << "없는 계좌 번호입니다. 다시 입력해주세요." << std::endl;
        std::cout << "계좌 번호 : "; std::cin >> withdrawAccountNumber;
        accountNumber = findAccount(withdrawAccountNumber);
    }

    // 출금
    withdrawAmount = account[accountNumber]->getBalance()- withdrawAmount;
    account[accountNumber]->setBalance(withdrawAmount);
}

void Bank::Inquire()
{
    std::cout << "전체 계좌를 조회합니다." << std::endl;
    for (int i = 0; i < totalCustomers; ++i)
    {
        std::cout << "계좌 : " << account[i]->getId() << std::endl;
        std::cout << "이름 : " << account[i]->getName() << std::endl;
        std::cout << "잔액 : " << account[i]->getBalance() << std::endl<<std::endl;
    }
}
