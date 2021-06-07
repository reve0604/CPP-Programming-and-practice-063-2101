#include "Bank.h"
#include "loan.h"
#include "saving.h"
#include <cstdlib>
// void Bank::client()함수 작성(예외처리)
// void Bank::BankManager()함수 작성(예외처리)

Bank::Bank() {
	num = 0;
}

void Bank::setAuthority(){
	int authority;
	
	do {
		cout << "1 : 고객		2 : 관리자" << endl;
		cin >> authority;
	} while (authority !=1 && authority !=2);

	if (authority == 1) {
		client();
	}
	else {
		BankManager();
	}
}


void Bank::client() {
	do {
		system("cls");

		cout << "0. 프로그램 종료" << endl;
		cout << "1. 계좌가입 " << endl;
		cout << "2. 계좌해지" << endl;
		cout << "3. 본인계좌정보출력" << endl;
		cout << "4. 입금" << endl;
		cout << "5. 출금" << endl;
		cout << "6. 적금" << endl;
		cout << "7. 대출" << endl;
		cout << "8. 첫 화면으로" << endl;

		int num;
		cout <<"\n\n"<<"0 ~ 8 번호 입력 : " << endl;
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
				cout << "0 ~ 8 사이의 번호를 입력해주세요." << endl;
			}
		}
	} while (true);
}

void Bank::BankManager() {
	do {
		system("cls");

		cout << "0. 프로그램 종료" << endl;
		cout << "1. 전체고객계좌출력" << endl;
		cout << "2. 단일고객계좌출력" << endl;
		cout << "3. 적금 관리" << endl;
		cout << "4. 대출 관리" << endl;
		cout << "5. 첫 화면으로" << endl;

		int num;
		cout <<"\n\n" << "0 ~ 5 번호 입력 : " << endl;
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
				cout << "0 ~ 5 사이의 번호를 입력해주세요." << endl; 
				system("PAUSE");

			}
		}
	} while (true);
}

void Bank::joinAccount() {
	ADB.addAccount();
}

void Bank::cancelAccount() {				// account.h의 GetAccId() 함수가 const로 되있는데 이것도 const로 설정??
	ADB.deleteAccount();
}

void Bank::allAccountsPrint() {
	ADB.showAllAccount();
}

void Bank::accountPrint() {
	int accountNum;

	cout << "계좌번호 입력 : ";
	cin >> accountNum;
	ADB.showAccount(accountNum);
}

void Bank::deposit() {
	int accountNum, depositMoney;
	cout << "계좌번호 입력 : ";
	cin >> accountNum;
	cout << "입금액 입력 : ";
	cin >> depositMoney;

	ADB.accountDeposit(accountNum, depositMoney);
}

void Bank::withdraw() {
	int accountNum, withdrawMoney;
	cout << "계좌번호 입력 : ";
	cin >> accountNum;
	cout << "출금액 입력 : ";
	cin >> withdrawMoney;

	ADB.accountWithdraw(accountNum, withdrawMoney);
}

void Bank::savig() {
	int num;
	do {
		system("cls");
		cout << "1: 적금" << endl;
		cout << "2: 적금 해지" << endl;
		cout << "3: 뒤로가기" << endl;
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
			cout << "1번과 2번 중 선택하세요" << endl;
			system("PAUSE");
		}
		}
	} while (true);
}
void Bank::savingManager() {
	while (true) {
		system("cls");
		int num;
		cout << "1: 적금 상품 내용 변경" << endl;
		cout << "2: 적금 상품 전체 조회" << endl;
		cout << "3: 뒤로가기" << endl;
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
				cout << "1과 2만 입력해주세요" << endl;
				system("PAUSE");
				break;
			}
		}
	}
}
void Bank::loan(){
	while (true) {
		system("cls");
		cout << "1: 대출" << endl;
		cout << "2: 대출 상환금 조회" << endl;
		cout << "3: 대출 상환" << endl;
		cout << "4: 뒤로가기" << endl;
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
				cout << "1 ~ 4 사이의 번호만 입력해주세요" << endl;
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
		cout << "1: 대출 상품 추가" << endl;
		cout << "2: 대출 상품 전체 조회" << endl;
		cout << "3: 뒤로가기" << endl;
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
				cout << "1과 2만 입력해주세요" << endl;
				system("PAUSE");
				break;
			}
		}
	}
}
