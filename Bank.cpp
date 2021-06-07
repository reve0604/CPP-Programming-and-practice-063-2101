#include "Bank.h"
#include "loan.h"
#include "saving.h"
#include <cstdlib>

Bank::Bank() {
	num = 0;
}

void Bank::setAuthority(){
	int authority;
	
	do {
		cout << "1 : ��		2 : ������" << endl;
		cin >> authority;
	} while (authority !=1 && authority !=2);

	if (authority == 1) {
		client();
	}
	else {
		BankManager();
	}
}

// ���� �۾�(�����, ��â��)  
void Bank::client() {
	do {
		system("cls");

		cout << "0. ���α׷� ����" << endl;
		cout << "1. ���°��� " << endl;
		cout << "2. ��������" << endl;
		cout << "3. ���ΰ����������" << endl;
		cout << "4. �Ա�" << endl;
		cout << "5. ���" << endl;
		cout << "6. ����" << endl;
		cout << "7. ����" << endl;
		cout << "8. ù ȭ������" << endl;

		int num;
		cout <<"\n\n"<<"0 ~ 8 ��ȣ �Է� : " << endl;
		cin >> num;
		switch (num)
		{
			case 1: {
				system("cls");
				joinAccount(); 
				break;
			}
			case 2: {
				system("cls");
				cancelAccount(); 
				break; 
			}
			case 3: {
				system("cls");
				accountPrint();
				break; 
			}
			case 4: {
				system("cls");
				deposit();
				break; 
			}
			case 5: {
				system("cls");
				withdraw();
				break; 
			}
			case 6: {
				system("cls");
				savig();
				break; 
			}
			case 7: {
				system("cls");
				loan();
				break; 
			}
			case 8: {
				system("cls");
				setAuthority();
				break; 
			}
			case 0: {
				return;
			}
			default: {
				cout << "0 ~ 8 ������ ��ȣ�� �Է����ּ���." << endl;
			}
		}
	} while (true);
}

// ���� �۾�(�����, ��â��) 
void Bank::BankManager() {
	do {
		system("cls");

		cout << "0. ���α׷� ����" << endl;
		cout << "1. ��ü���������" << endl;
		cout << "2. ���ϰ��������" << endl;
		cout << "3. ���� ����" << endl;
		cout << "4. ���� ����" << endl;
		cout << "5. ù ȭ������" << endl;

		int num;
		cout <<"\n\n" << "0 ~ 5 ��ȣ �Է� : " << endl;
		cin >> num;
		switch (num)
		{
			case 1: {
				system("cls");
				allAccountsPrint(); 
				break;
			}
			case 2: {
				system("cls");
				accountPrint(); 
				break;
			}
			case 3: {
				system("cls");
				savingManager();
				break;
			
			}
			case 4: {
				system("cls");
				loanManager();
				break;
			}
			case 5: {
				system("cls");
				setAuthority();
				break; 
			}
			case 0: {
				return;
			}
			default: {
				cout << "0 ~ 5 ������ ��ȣ�� �Է����ּ���." << endl; 
				system("PAUSE");

			}
		}
	} while (true);
}

void Bank::joinAccount() {
	ADB.addAccount();
}

void Bank::cancelAccount() {				// account.h�� GetAccId() �Լ��� const�� ���ִµ� �̰͵� const�� ����??
	ADB.deleteAccount();
}

void Bank::allAccountsPrint() {
	ADB.showAllAccount();
}

void Bank::accountPrint() {
	int accountNum;

	cout << "���¹�ȣ �Է� : ";
	cin >> accountNum;
	ADB.showAccount(accountNum);
}

void Bank::deposit() {
	int accountNum, depositMoney;
	cout << "���¹�ȣ �Է� : ";
	cin >> accountNum;
	cout << "�Աݾ� �Է� : ";
	cin >> depositMoney;

	ADB.accountDeposit(accountNum, depositMoney);
}

void Bank::withdraw() {
	int accountNum, withdrawMoney;
	cout << "���¹�ȣ �Է� : ";
	cin >> accountNum;
	cout << "��ݾ� �Է� : ";
	cin >> withdrawMoney;

	ADB.accountWithdraw(accountNum, withdrawMoney);
}

void Bank::savig() {
	int num;
	do {
		system("cls");
		cout << "1: ����" << endl;
		cout << "2: ���� ����" << endl;
		cout << "3: �ڷΰ���" << endl;
		cin >> num;
		switch (num) {
		case 1: {
			system("cls");
			savingObj.doSaving(ADB);
			system("PAUSE");
			break;
		}
		case 2: {
			system("cls");
			savingObj.withdraw(ADB);
			system("PAUSE");
			break;
		}
		case 3: {
			return;
		}
		default: {
			cout << "1���� 2�� �� �����ϼ���" << endl;
			system("PAUSE");
		}
		}
	} while (true);
}
void Bank::savingManager() {
	while (true) {
		system("cls");
		int num;
		cout << "1: ���� ��ǰ ���� ����" << endl;
		cout << "2: ���� ��ǰ ��ü ��ȸ" << endl;
		cout << "3: �ڷΰ���" << endl;
		cin >> num;
		switch (num)
		{
			case 1: {
				savingObj.changeSavingItemCatalogue();
				break;
			}
			case 2: {
				system("cls");
				savingObj.showAllSavingItemCatalogue();
				system("PAUSE");
				break;
			}
			case 3: {
				return;
			}
			default: {
				cout << "1�� 2�� �Է����ּ���" << endl;
				system("PAUSE");
				break;
			}
		}
	}
}
void Bank::loan(){
	while (true) {
		system("cls");
		cout << "1: ����" << endl;
		cout << "2: ���� ��ȯ�� ��ȸ" << endl;
		cout << "3: ���� ��ȯ" << endl;
		cout << "4: �ڷΰ���" << endl;
		cin >> num;
		switch (num) {
			case 1: {
				system("cls");
				loanObj.getLoan();
				system("PAUSE");
				break;
			}
			case 2: {
				system("cls");
				loanObj.payBackCheck();
				system("PAUSE");
				break;
			}
			case 3:{
				system("cls");
				loanObj.payBack(); 
				system("PAUSE");
				break;
			}
			case 4: {
				return;
			}
			default: {
				cout << "1 ~ 4 ������ ��ȣ�� �Է����ּ���" << endl;
				system("PAUSE");
				break;
			}
		}
	}
}
void Bank::loanManager() {
	while (true) {
		system("cls");
		int num;
		cout << "1: ���� ��ǰ �߰�" << endl;
		cout << "2: ���� ��ǰ ��ü ��ȸ" << endl;
		cout << "3: �ڷΰ���" << endl;
		cin >> num;
		switch (num)
		{
			case 1: {
				system("cls");
				loanObj.addLoanItemMenu();
				system("PAUSE");
				break;
			}
			case 2: {
				system("cls");
				loanObj.showLoanItemMenu();
				system("PAUSE");
				break;
			}
			case 3: {
				return;
			}
			default: {
				cout << "1�� 2�� �Է����ּ���" << endl;
				system("PAUSE");
				break;
			}
		}
	}
}
