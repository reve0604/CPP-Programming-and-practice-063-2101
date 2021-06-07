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
	int temp = 1 * pow(10, 9);  // ù��° ���ڴ� 1�� ���� (overflow ����) 
	for (int i = 8; i >= 0; i--)
	{
		temp += (rand() * 10 / (RAND_MAX + 1)) * pow(10, i);  // 0 ~ 9������ ���� ���� 
	}
	accID = temp;
	
	// ��й�ȣ ����  
	char a[10];
	int i = 0;
	
	cout << "��й�ȣ 6�ڸ��� ����ϼ���: ";
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
	cout << "���°� �����Ǿ����ϴ�." << endl;
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
	cout << money << " ���� �ԱݵǾ����ϴ�." << endl;
	ShowAccInfo();
	system("PAUSE");
}

int Account::Withdraw(int money)
{	
	if(balance<money)
	{
		cout << "�ܾ��� �����մϴ�." << endl;	
		system("PAUSE");
		return 0;
	}
		
	cout << "��й�ȣ 6�ڸ��� �Է��ϼ���: ";
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
		cout << "�ܾ��� " << balance << "���Դϴ�." << endl; 
		system("PAUSE");
		return money;
	}
	else
	{
		cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
		system("PAUSE");
		return Withdraw(money);
	}
}

void Account::ShowAccInfo() const 
{
	cout<<"���¹�ȣ: "<<accID<<endl;
	cout<<"��    ��: "<<cusName<<endl;
	cout<<"��    ��: "<<balance<<endl;
}
