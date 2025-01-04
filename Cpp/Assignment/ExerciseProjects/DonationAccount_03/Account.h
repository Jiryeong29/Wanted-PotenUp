#pragma once


//  계좌번호(int id), 고객 이름(char* name), 고객의 잔액(int balance)
class Account
{
public:
	// 기본 생성자.
	Account();

	// 복사 생성자.
	Account(const Account& other);

	// 복사 대입 연산자.	
	Account& operator=(const Account& other);
	// 생성자.
	Account(const int id,const char* name,const int balance );

	virtual void deposit(int depositAmount);


	// getter setter
	int getId() const { return _id; }
	char* getName() const { return _name; }
	int getBalance() const { return _balance; }

	void setId(const int id) { _id = id; }
	void setName(const char* name);
	void setBalance(const int balance) { _balance = balance; }

	virtual void DonationInfo();

	virtual ~Account();
protected:
	int _id;			// 계좌 번호
	char* _name;	// 이름
	int _balance;	// 잔액

};

