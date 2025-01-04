#pragma once
#include "Account.h"
// 1. 입금액의 1%에 해당하는 금액을 사회 기부금으로 환원
// 2. 기부 계좌는 기부된 총 금액에 대한 정보를 제공한다. 
// 3. 잔액을 조회할 때 기부된 총 금액도 함께 조회되어야 한다. 
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

