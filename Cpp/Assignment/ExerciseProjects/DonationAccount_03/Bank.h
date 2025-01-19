#pragma once

class Account;

class Bank
{
public:
	// 기본 생성자.
	Bank();
	//Bank();

	// 소멸자.
	~Bank();

	void CreateAccount(int accountType);	// 계좌 개설
	void Deposit();			// 예금
	void WithDraw();		// 출금
	void Inquire();			// 전체 잔액 조회

	bool findAccount(int accountNumber);		// 계좌 찾기
private:
	Account* account[100];

	int totalCustomers;

	// 복사 생성자.
	Bank(const Bank& other) = delete;
	// 복사 대입 생성자.
	Bank& operator=(const Bank& other) = delete;
};

