#include "CreditAccount.h"



CreditAccount::CreditAccount(int id, const char* name, int balance, const char* accountType)
	: Account(id, name, balance, accountType), interestRate(0.01f)
{
}

void CreditAccount::deposit(int depositAmount)
{
	Account::deposit((depositAmount + (depositAmount*interestRate))); // �Ա� �ݾ�? �Ա� �� �ݾ�?
}

CreditAccount::~CreditAccount()
{
}
