#pragma once
#include "Account.h"
#include <vector>


class AccountDB
{
private:
	vector <Account> DB;
public:
	AccountDB();
	void addAccount();				// ���� �۾�(�����, ��â��) 
	void showAllAccount();			
	void showAccount(int accID);
	string GetName(int idx);
	void sortAccount();
	int lengthAccountDB();
	int searchAccount(int start_index, int end_index, int accID);
	void deleteAccount();
	void accountDeposit(int accID, int money);
	void accountWithdraw(int accID, int money);
};
