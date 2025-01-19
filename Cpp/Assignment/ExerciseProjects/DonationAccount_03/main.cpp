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
		 std::cout << "1. 일반계좌 개설" << std::endl;
		 std::cout << "2. 신용계좌 개설" << std::endl;
		 std::cout << "3. 기부계좌 개설" << std::endl;
		 std::cout << "Q. 종료 " << std::endl;
		 std::cout << "메뉴 입력 : "; std::cin >> accountMenu;

		 if (accountMenu == 'q' || accountMenu == 'Q')
		 {
			 std::cout << "메인 메뉴로 돌아갑니다." << std::endl;
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
		std::cout << "1. 계좌 개설" << std::endl;
		std::cout << "2. 입금" << std::endl;
		std::cout << "3. 출금" << std::endl;
		std::cout << "4. 전체 계좌 조회 " << std::endl;
		std::cout << "Q. 종료 " << std::endl;


		std::cout << "메뉴 입력 : "; std::cin >> inputMenu;

		if (inputMenu == 'q' || inputMenu == 'Q')
		{
			std::cout << "감사합니다. 또 방문해 주세요." << std::endl;
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