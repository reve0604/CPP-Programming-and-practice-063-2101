#include "AccountDB.h"
#include <algorithm>

bool compareFunction(const Account& o1, const Account& o2) {
	return o1.GetAccID() < o2.GetAccID();
}

AccountDB::AccountDB() {}

// ���� �۾�(�����, ��â��) 
void AccountDB::addAccount() {
	int balance;
	string cusName;
	cout << "-----------------------" << endl;
	cout << "�ű� ���� ���� ������" << endl;
	cout << "���»����� �Աݱݾ� :";
	cin >> balance;
	cout << "�̸� :";
	cin >> cusName;
	
	if(DB.size() == 0)
	{
		Account temp = Account(balance, cusName);
		DB.push_back(temp);
		temp.ShowAccInfo();
		system("PAUSE");
	}
	else
	{
		while(true)
		{
			Account temp = Account(balance, cusName);
			int index = searchAccount(0, lengthAccountDB() - 1, temp.GetAccID());
			if (index == -1) {
				DB.push_back(temp);

				temp.ShowAccInfo();
				system("PAUSE");
				break;
			}
		}
	}
	sortAccount();
}

void AccountDB::showAllAccount() {
	for (int i = 0; i < DB.size(); i++) {
		cout << "-----------------------" << endl;
		DB[i].ShowAccInfo();
	}
	system("PAUSE");
}

void AccountDB::showAccount(int accID) {
	int idx = searchAccount(0, lengthAccountDB() - 1, accID);
	if (idx == -1) {
		cout << "��ġ�ϴ� ���¹�ȣ�� �����ϴ�." << endl;
		system("PAUSE");
	}
	else {
		DB[idx].ShowAccInfo();
		system("PAUSE");
	}

}

string AccountDB::GetName(int idx) {
	return DB[idx].GetName();
}


void AccountDB::sortAccount() { // �������� ����
	sort(DB.begin(), DB.end(), compareFunction);
}

int AccountDB::lengthAccountDB() { // ADB ������ ���� �� ��ȯ
	return DB.size();
}

int AccountDB::searchAccount(int start_index, int end_index, int accID) { // ADB ���� ���� �Է¹��� accID�� ��ġ�ϴ� ������ �ε��� ���� ��ȯ�Ѵ�.
	int middle = (start_index + end_index) / 2;							  // ��ġ�ϴ� ���Ұ� �������� �ʴ� ��� -1�� ��ȯ�Ѵ�.
	if (end_index - start_index == 1) {
		if (DB[start_index].GetAccID() == accID) {
			return start_index;
		}
		else if (DB[end_index].GetAccID() == accID) {
			return end_index;
		}
		else {
			return -1;
		}
	}
	if (end_index == start_index) {
		if (DB[start_index].GetAccID() == accID) {
			return start_index;
		}
		else {
			return -1;
		}
	}
	if (DB[middle].GetAccID() == accID) {
		return middle;
	}
	else if (DB[middle].GetAccID() > accID) {
		return searchAccount(start_index, middle, accID);
	}
	else {
		return searchAccount(middle, end_index, accID);
	}
}

void AccountDB::deleteAccount() {
	int accID;

	while (true) {
		cout << "������ ������ ���¹�ȣ�� �Է��ϼ��� : ";
		cin >> accID;

		int idx = searchAccount(0, lengthAccountDB() - 1, accID);

		if (idx == -1) {
			cout << "��ġ�ϴ� ���¹�ȣ�� �����ϴ�." << endl;
			system("PAUSE");
		}
		else {
			cout << "�Է��Ͻ� ���°� �����Ǿ����ϴ�." << endl;
			DB.erase(DB.begin() + idx);
			system("PAUSE");
			break;
		}
	}
}

void AccountDB::accountDeposit(int accID, int money) {
	int idx = searchAccount(0, lengthAccountDB() - 1, accID);
	if (idx == -1) {
		cout << "��ġ�ϴ� ���¹�ȣ�� �����ϴ�." << endl;
		system("PAUSE");
	}
	else {
		DB[idx].Deposit(money);
		system("PAUSE");
	}
}
void AccountDB::accountWithdraw(int accID, int money) {
	int idx = searchAccount(0, lengthAccountDB() - 1, accID);
	if (idx == -1) {
		cout << "��ġ�ϴ� ���¹�ȣ�� �����ϴ�." << endl;
		system("PAUSE");
	}
	else {
		DB[idx].Withdraw(money);
		system("PAUSE");
	}
}
