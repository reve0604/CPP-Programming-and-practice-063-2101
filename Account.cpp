#include "Account.h"
#include "AccountDB.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <conio.h>
#include <Windows.h>

Account::Account(int money, string name)
	: balance(money), cusName(name)
{
	srand((unsigned int)time(NULL));
	int temp = 1 * pow(10, 9);  // 첫번째 숫자는 1로 시작 (overflow 때문) 
	for (int i = 8; i >= 0; i--)
	{
		temp += (rand() * 10 / (RAND_MAX + 1)) * pow(10, i);  // 0 ~ 9까지의 난수 생성 
	}
	accID = temp;
	
	// 비밀번호 설정  
	char a[10];
	int i = 0;
	
	cout << "비밀번호 6자리를 등록하세요: ";
	while (i != 6)
	{
		if (_kbhit())
		{
			a[i] = _getch();
			if (a[i] == 13)
			{
	    		break;
	   		}
	   		i++;
			cout << "*";
	    }
	}
	cout << endl;
	int result = 0;
	for(int i = 5; i >= 0; i--)
	{
		result += (static_cast<int>(a[5 - i]) - 48) * pow(10, i);
	}
	password = result;
	cout << "계좌가 생성되었습니다." << endl;
}

Account::Account(const Account & ref)
	: accID(ref.accID), balance(ref.balance), cusName(ref.cusName), password(ref.password)
{ }

int Account::GetAccID() const {
	return accID; 
}

string Account::GetName() const {
	return cusName;
}

int Account::GetPassword() const {
	return password; 
}

void Account::Deposit(int money)
{
	balance+=money;
	cout << money << " 원이 입금되었습니다." << endl;
	ShowAccInfo();
	system("PAUSE");
}

int Account::Withdraw(int money)
{	
	if(balance<money)
	{
		cout << "잔액이 부족합니다." << endl;	
		system("PAUSE");
		return 0;
	}
		
	cout << "비밀번호 6자리를 입력하세요: ";
	char a[10];
	int i = 0;
	
	while (i != 6)
	{
		if (_kbhit())
		{
			a[i] = _getch();
			if (a[i] == 13)
			{
	    		break;
	   		}
	   		i++;
			cout << "*";
	    }
	}
	cout << endl;
	int result = 0;
	for(int i = 5; i >= 0; i--)
	{
		result += (static_cast<int>(a[5 - i]) - 48) * pow(10, i);
	}
	
	if(this->password == result)
	{
		balance-=money;
		cout << "잔액은 " << balance << "원입니다." << endl; 
		system("PAUSE");
		return money;
	}
	else
	{
		cout << "비밀번호가 일치하지 않습니다." << endl;
		system("PAUSE");
		return Withdraw(money);
	}
}

void Account::ShowAccInfo() const 
{
	cout<<"계좌번호: "<<accID<<endl;
	cout<<"이    름: "<<cusName<<endl;
	cout<<"잔    액: "<<balance<<endl;
}
