#pragma once
#include <fstream>
class Account;

class Bank
{
public:

	// �⺻ ������.
	Bank();
	//Bank();

	// �Ҹ���.
	~Bank();

	void CreateAccount(int accountType);	// ���� ����
	void Deposit();			// ����
	void WithDraw();		// ���
	void Inquire();			// ��ü �ܾ� ��ȸ

	void putData();
	bool findAccount(int accountNumber);		// ���� ã��
private:
	Account* account[100];

	int totalCustomers;

	std::ofstream fout;
	std::ifstream  fin;

	// ���� ������.
	Bank(const Bank& other) = delete;
	// ���� ���� ������.
	Bank& operator=(const Bank& other) = delete;
};

