#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;

class Account
{
private:
	int accID; 
	int balance;
	int password;    // 6자리 숫자로 구성     
	string cusName;
public:
	Account(int money, string name);
	Account(const Account & ref);

	int GetAccID() const;
	string GetName() const;
	int GetPassword() const;
	void Deposit(int money);
	virtual int Withdraw(int money) ;
	void ShowAccInfo() const ;
};
#endif
