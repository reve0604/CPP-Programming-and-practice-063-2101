#include "AccountDB.h"
#include <algorithm>
// void AccountDB::addAccount() 함수 작성(if문 부분)

bool compareFunction(const Account& o1, const Account& o2) {
	return o1.GetAccID() < o2.GetAccID();
}

AccountDB::AccountDB() {}

void AccountDB::addAccount() {
	int balance;
	string cusName;
	cout << "-----------------------" << endl;
	cout << "신규 계좌 생성 페이지" << endl;
	cout << "계좌생성시 입금금액 :";
	cin >> balance;
	cout << "이름 :";
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
		cout << "일치하는 계좌번호가 없습니다." << endl;
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


void AccountDB::sortAccount() { // 오름차순 정렬
	sort(DB.begin(), DB.end(), compareFunction);
}

int AccountDB::lengthAccountDB() { // ADB 벡터의 원소 수 반환
	return DB.size();
}

int AccountDB::searchAccount(int start_index, int end_index, int accID) { // ADB 벡터 내에 입력받은 accID와 일치하는 원소의 인덱스 값을 반환한다.
	int middle = (start_index + end_index) / 2;							  // 일치하는 원소가 존재하지 않는 경우 -1을 반환한다.
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
		cout << "삭제할 계좌의 계좌번호를 입력하세요 : ";
		cin >> accID;

		int idx = searchAccount(0, lengthAccountDB() - 1, accID);

		if (idx == -1) {
			cout << "일치하는 계좌번호가 없습니다." << endl;
			system("PAUSE");
		}
		else {
			cout << "입력하신 계좌가 삭제되었습니다." << endl;
			DB.erase(DB.begin() + idx);
			system("PAUSE");
			break;
		}
	}
}

void AccountDB::accountDeposit(int accID, int money) {
	int idx = searchAccount(0, lengthAccountDB() - 1, accID);
	if (idx == -1) {
		cout << "일치하는 계좌번호가 없습니다." << endl;
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
		cout << "일치하는 계좌번호가 없습니다." << endl;
		system("PAUSE");
	}
	else {
		DB[idx].Withdraw(money);
		system("PAUSE");
	}
}
