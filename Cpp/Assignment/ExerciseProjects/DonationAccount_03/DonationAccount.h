#pragma once
#include "Account.h"
// 1. �Աݾ��� 1%�� �ش��ϴ� �ݾ��� ��ȸ ��α����� ȯ��
// 2. ��� ���´� ��ε� �� �ݾ׿� ���� ������ �����Ѵ�. 
// 3. �ܾ��� ��ȸ�� �� ��ε� �� �ݾ׵� �Բ� ��ȸ�Ǿ�� �Ѵ�. 
class DonationAccount : public Account
{
public:
	DonationAccount(int id, const char* name, int balance);

	~DonationAccount() ;

	void deposit(int depositAmount) override;
	void DonationInfo() override;
private:
	float donateRate;
	int donataAmount;
};

