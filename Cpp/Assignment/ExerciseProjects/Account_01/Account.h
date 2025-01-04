#pragma once


//  ���¹�ȣ(int id), �� �̸�(char* name), ���� �ܾ�(int balance)
class Account
{
public:
	// �⺻ ������.
	Account();

	// ���� ������.
	Account(const Account& other);

	// ���� ���� ������.	
	Account& operator=(const Account& other);
	// ������.
	Account(const int id,const char* name,const int balance );


	// getter setter
	int getId() const { return _id; }
	char* getName() const { return _name; }
	int getBalance() const { return _balance; }

	void setId(const int id) { _id = id; }
	void setName(const char* name);
	void setBalance(const int balance) { _balance = balance; }

	void print();
	~Account();
private:
	int _id;			// ���� ��ȣ
	char* _name;	// �̸�
	int _balance;	// �ܾ�

};

