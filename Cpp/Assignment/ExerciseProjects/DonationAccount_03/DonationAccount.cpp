#include "DonationAccount.h"
#include <iostream>
DonationAccount::DonationAccount(int id, const char* name, int balance)
	:Account(id, name, balance), donateRate(0.01f), donataAmount(0)
{
}

void DonationAccount::deposit(int depositAmount)
{
	Account::deposit(depositAmount); 
	donataAmount += (depositAmount * donateRate);
	std::cout << "기부 금액 : " << donataAmount << std::endl;
}

void DonationAccount::DonationInfo()
{
	std::cout << "총 기부 금액 : " << donataAmount << std::endl<< std::endl;
}

DonationAccount::~DonationAccount()
{
}