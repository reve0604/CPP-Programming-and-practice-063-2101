#include "Saving.h"

Saving::Saving(){}

void Saving::doSaving(AccountDB ADB) {
	int accID;
	string answer;
	int savingItemNumber;
	int savingMoney;
	int AccountIndex;
	string cusName;

	cout << "적금가입을 위해서 본인 명의의 입출금 계좌가 존재해야 합니다." << endl;
	cout << "계좌번호를 입력하세요 : ";
	cin >> accID;
	if (ADB.lengthAccountDB() == 0) {
		cout << "계좌번호를 확인해주세요, 만약 계좌가 없다면 계좌를 생성해주세요." << endl;
		return;
	}
	if (ADB.searchAccount(0,ADB.lengthAccountDB()-1,accID) == -1) { 
		cout << "계좌번호를 확인해주세요, 만약 계좌가 없다면 계좌를 생성해주세요." << endl;
		return;
	}
	else {
		AccountIndex = ADB.searchAccount(0, ADB.lengthAccountDB() - 1, accID);
	}
	
	cout << "적금상품을 조회하시겠습니까? (Y / N) :";
	cin >> answer;
	while (1){
		if (answer == "Y") {
			system("cls");
			saveArr.getAllSavingItemCatalogue();
			break;
		}
		else if (answer == "N") {
			break;
		}
		else {
			cout << "응답은 (Y / N)로 해주세요" << endl;
			cout << "적금상품을 조회하시겠습니까? (Y / N) :" << endl;
			cin >> answer;
		}
	}

	cout << "적금하고자 하는 상품의 번호를 입력해주세요 :";
	cin >> savingItemNumber;
	savingItemNumber -= 1;

	system("cls");
	saveArr.choiceSavingItemCatalogue(savingItemNumber);
	while (true) {
		cout << "매 월 납입하고자 하는 금액을 입력하세요 : ";
		cin >> savingMoney;

		if ((savingMoney <= saveArr.getSavingItemMoneyRate(savingItemNumber)) && (savingMoney > 0)) {
			break;
		}
		else {
			cout << "납입가능한 범위를 벗어났습니다." << endl;
		}
	}
	
	cusName = ADB.GetName(AccountIndex);
	savingAccountDB.addAccount(cusName, saveArr.getSavingItemRate(savingItemNumber), savingMoney, saveArr.getSavingItemDate(savingItemNumber));
	savingAccountDB.showAllSavingAccount();
	system("PAUSE");
}


void Saving::withdraw(AccountDB ADB)    // 납입기간을 입력하고 납입기간 이후 해지시 수령금을 출력  
{
	int date;
	int accID;
	int savingAccountIndex;
	int total = 0;
	bool isEarlyCancle = false;

	cout << "적금계좌번호를 작성해주세요 : ";
	cin >> accID;
	if (savingAccountDB.lengthSavingAccountDB() == 0) {
		cout << "입력하신 적금계좌가 존재하지 않습니다." << endl;
		return;
	}
	if (savingAccountDB.searchSavingAccount(0, savingAccountDB.lengthSavingAccountDB() - 1, accID) == -1) {
		cout << "입력하신 적금계좌가 존재하지 않습니다." << endl;
		return;
	}
	else {
		savingAccountIndex = savingAccountDB.searchSavingAccount(0, savingAccountDB.lengthSavingAccountDB() - 1, accID);
	}
	cout << "납입 기간을 작성해주세요 : ";
	cin >> date;
	double rate = savingAccountDB.getRate(savingAccountIndex);
	int savingMoney = savingAccountDB.getMoney(savingAccountIndex);

	if (date < savingAccountDB.getDate(savingAccountIndex)) {
		cout << "중도해지 시 중도해지 이율이 적용됩니다." << endl;
		isEarlyCancle = true;
	}
	if(isEarlyCancle)  {
		rate *= 0.1;    // 중도해지시 기존 이자율에 10%만 적용  
	}

	for (int i = 1; i <= date; i++)
	{
		total += savingMoney + (savingMoney * (rate / 100.0) * (i / 12.0));  // 잔고에 대한 이자추가
	}
	cout << date << "개월 납입 후 해지 시 " << total << " 원을 수령할 수 있습니다." << endl;
}

void Saving::setSavingItemCatalogue() {
	saveArr.setSavingItemCatalogue();
}

void Saving::changeSavingItemCatalogue() {
	saveArr.changeSavingItemCatalogue();
}
void Saving::showAllSavingItemCatalogue() {
	saveArr.getAllSavingItemCatalogue();
}
