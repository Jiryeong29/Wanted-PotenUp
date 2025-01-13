#pragma once
#include "Account.h"

// 입금 때마다 1%의 이자를 준다
class CreditAccount : public Account
{
public:
	CreditAccount(int id, const char* name, int balance, const char *accountType);

	~CreditAccount();

	void deposit(int depositAmount) override;
private:

	float interestRate;
};

