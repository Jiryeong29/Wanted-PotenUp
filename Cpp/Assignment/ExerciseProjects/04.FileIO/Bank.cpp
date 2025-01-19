#include "Bank.h"
#include "Account.h"
#include "CreditAccount.h"
#include "DonationAccount.h"
#include <iostream>
Bank::Bank()

    : fout("customerInfo.txt", std::ios_base::out), // 파일을 append 모드로 열기  
    fin("customerInfo.txt", std::ios_base::in), // 파일을 append 모드로 열기  
    totalCustomers(0)
{
    if (fout.is_open())
    {
        std::cout << "파일열기 성공\n";
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
    // 고객 수가 100명이 넘었을 때
    if (totalCustomers > 100)
    {
        std::cout << "최대 계좌 개설 수에 도달하여 계좌를 개설할 수 없습니다." << std::endl;
        return;
    }

    // 임시로 입력 받을 변수들
    int id, balance;
    char name[100];

    // 고객 계좌 입력
    std::cout << "계좌를 개설하겠습니다. 정보를 입력해주세요." << std::endl;
    std::cout << "계좌 : "; std::cin >> id;
    std::cout << "이름 : "; std::cin >> name;
    std::cout << "잔액 : "; std::cin >> balance;

    // 고객 계좌 생성
    switch (accountType)
    {
    case 1: // 일반 계좌
        account[totalCustomers] = new Account(id, name, balance, "일반계좌");
        ++totalCustomers;
        break;
    case 2: // 신용 계좌
        account[totalCustomers] = new CreditAccount(id, name, balance, "신용계좌");
        ++totalCustomers;
        break;
    case 3: // 기부 계좌
        account[totalCustomers] = new DonationAccount(id, name, balance, "기부계좌");
        ++totalCustomers;
        break;
    default:
        break;
    }
}

void Bank::putData()
{
    int cnt = 0;
    while (1)
    {
        if (totalCustomers == cnt)
        {
            return;
        }
        fout << "---------------\n";
        fout << "고객 이름  :" << account[cnt]->getName() << "\n";
        fout << "계좌 번호  :  " << account[cnt]->getId() << "\n";
        fout << "계좌 종류  : " << account[cnt]->getAccountType() << "\n";
        fout << "총 잔액    : " << account[cnt]->getBalance() << "\n";
        fout << "---------------\n";
        ++cnt;
    }
}

bool Bank::findAccount(int AccountNumber)
{
    if (totalCustomers == 0)
    {
        std::cout << "개설된 계좌가 하나도 없습니다...계좌를 개설해주세요.." << std::endl;
        return false;
    }

    for (int i = 0; i < totalCustomers; ++i)
    {
        if (account[i]->getId() == AccountNumber)
        {
            std::cout << "입금하시려는 계좌를 찾았습니다\n";
            return true;
        }
    }

    std::cout << "입금하시려는 계좌를 찾지 못했습니다. 다시 입력해주세요\n";

    return false;
}
void Bank::Deposit()
{
    std::cout << "입금 금액과 입금하시려는 계좌번호를 입력해주세요." << std::endl;
    // 입력받기 위해 선언한 변수들
    int depositAmount;              // 입금한 금액
    int depositAccountNumber;       // 입금할 계좌 번호
    std::cout << "입금 금액 : "; std::cin >> depositAmount;
    std::cout << "계좌 번호 : "; std::cin >> depositAccountNumber;

    // 계좌가 없을 경우 계속 입력 받기
    while (!(findAccount(depositAccountNumber) == true))
    {
        std::cout << "없는 계좌 번호입니다. 다시 입력해주세요." << std::endl;
        std::cout << "계좌 번호 : "; std::cin >> depositAccountNumber;
    }

    // 입금
    account[depositAccountNumber]->deposit(depositAmount);


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
    account[accountNumber]->setBalance(account[accountNumber]->getBalance() - withdrawAmount);
}

void Bank::Inquire()
{
    std::cout << "전체 계좌를 조회합니다." << std::endl;
    for (int i = 0; i < totalCustomers; ++i)
    {
        std::cout << "계좌 : " << account[i]->getId() << std::endl;
        std::cout << "이름 : " << account[i]->getName() << std::endl;
        std::cout << "잔액 : " << account[i]->getBalance() << std::endl;

        account[i]->DonationInfo();
        std::cout << std::endl;
    }
}
