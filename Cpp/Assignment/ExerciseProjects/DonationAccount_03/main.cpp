#include <iostream>
#include "Account.h"
#include "Bank.h"
enum MENU
{
	CREATE=1,
	DEPOSIT,
	WITHDRAW,
	INQUIRE
};
 enum ACCOUNT
{
	NORMAL =1,
	CREDIT,
	DONATION
};

 void createAccountMenu(Bank& bank)
 {
	 char accountMenu;
	 while (1)
	 {
		 std::cout << "1. �Ϲݰ��� ����" << std::endl;
		 std::cout << "2. �ſ���� ����" << std::endl;
		 std::cout << "3. ��ΰ��� ����" << std::endl;
		 std::cout << "Q. ���� " << std::endl;
		 std::cout << "�޴� �Է� : "; std::cin >> accountMenu;

		 if (accountMenu == 'q' || accountMenu == 'Q')
		 {
			 std::cout << "���� �޴��� ���ư��ϴ�." << std::endl;
			 break;
		 }
		 accountMenu -= '0';
		 bank.CreateAccount(accountMenu);
	 }
 }

void mainMenu(Bank& bank)
{
	char inputMenu;

	while (1)
	{
		std::cout << "1. ���� ����" << std::endl;
		std::cout << "2. �Ա�" << std::endl;
		std::cout << "3. ���" << std::endl;
		std::cout << "4. ��ü ���� ��ȸ " << std::endl;
		std::cout << "Q. ���� " << std::endl;


		std::cout << "�޴� �Է� : "; std::cin >> inputMenu;

		if (inputMenu == 'q' || inputMenu == 'Q')
		{
			std::cout << "�����մϴ�. �� �湮�� �ּ���." << std::endl;
			break;
		}
		
		switch (inputMenu-'0')
		{
		case CREATE:
			createAccountMenu(bank);
			break;
		case DEPOSIT:
			bank.Deposit();
			break;
		case WITHDRAW:
			bank.WithDraw();
			break;
		case INQUIRE:
			bank.Inquire();
			break;
		default:
			break;

		}
	}

}
int main()
{
	Bank kakaobank;

	mainMenu(kakaobank);

}