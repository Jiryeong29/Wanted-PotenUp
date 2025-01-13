#pragma once
#include "Account.h"

// �Ա� ������ 1%�� ���ڸ� �ش�
class CreditAccount : public Account
{
public:
	CreditAccount(int id, const char* name, int balance, const char *accountType);

	~CreditAccount();

	void deposit(int depositAmount) override;
private:

	float interestRate;
};

