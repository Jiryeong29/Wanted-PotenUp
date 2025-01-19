#include "CreditAccount.h"



CreditAccount::CreditAccount(int id, const char* name, int balance, const char* accountType)
	: Account(id, name, balance, accountType), interestRate(0.01f)
{
}

void CreditAccount::deposit(int depositAmount)
{
	Account::deposit((depositAmount + (depositAmount*interestRate))); // 입금 금액? 입금 후 금액?
}

CreditAccount::~CreditAccount()
{
}
