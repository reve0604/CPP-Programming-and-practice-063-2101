#include "Saving.h"

Saving::Saving(){}

void Saving::doSaving(AccountDB ADB) {
	int accID;
	string answer;
	int savingItemNumber;
	int savingMoney;
	int AccountIndex;
	string cusName;

	cout << "���ݰ����� ���ؼ� ���� ������ ����� ���°� �����ؾ� �մϴ�." << endl;
	cout << "���¹�ȣ�� �Է��ϼ��� : ";
	cin >> accID;
	if (ADB.lengthAccountDB() == 0) {
		cout << "���¹�ȣ�� Ȯ�����ּ���, ���� ���°� ���ٸ� ���¸� �������ּ���." << endl;
		return;
	}
	if (ADB.searchAccount(0,ADB.lengthAccountDB()-1,accID) == -1) { 
		cout << "���¹�ȣ�� Ȯ�����ּ���, ���� ���°� ���ٸ� ���¸� �������ּ���." << endl;
		return;
	}
	else {
		AccountIndex = ADB.searchAccount(0, ADB.lengthAccountDB() - 1, accID);
	}
	
	cout << "���ݻ�ǰ�� ��ȸ�Ͻðڽ��ϱ�? (Y / N) :";
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
			cout << "������ (Y / N)�� ���ּ���" << endl;
			cout << "���ݻ�ǰ�� ��ȸ�Ͻðڽ��ϱ�? (Y / N) :" << endl;
			cin >> answer;
		}
	}

	cout << "�����ϰ��� �ϴ� ��ǰ�� ��ȣ�� �Է����ּ��� :";
	cin >> savingItemNumber;
	savingItemNumber -= 1;

	system("cls");
	saveArr.choiceSavingItemCatalogue(savingItemNumber);
	while (true) {
		cout << "�� �� �����ϰ��� �ϴ� �ݾ��� �Է��ϼ��� : ";
		cin >> savingMoney;

		if ((savingMoney <= saveArr.getSavingItemMoneyRate(savingItemNumber)) && (savingMoney > 0)) {
			break;
		}
		else {
			cout << "���԰����� ������ ������ϴ�." << endl;
		}
	}
	
	cusName = ADB.GetName(AccountIndex);
	savingAccountDB.addAccount(cusName, saveArr.getSavingItemRate(savingItemNumber), savingMoney, saveArr.getSavingItemDate(savingItemNumber));
	savingAccountDB.showAllSavingAccount();
	system("PAUSE");
}


void Saving::withdraw(AccountDB ADB)    // ���ԱⰣ�� �Է��ϰ� ���ԱⰣ ���� ������ ���ɱ��� ���  
{
	int date;
	int accID;
	int savingAccountIndex;
	int total = 0;
	bool isEarlyCancle = false;

	cout << "���ݰ��¹�ȣ�� �ۼ����ּ��� : ";
	cin >> accID;
	if (savingAccountDB.lengthSavingAccountDB() == 0) {
		cout << "�Է��Ͻ� ���ݰ��°� �������� �ʽ��ϴ�." << endl;
		return;
	}
	if (savingAccountDB.searchSavingAccount(0, savingAccountDB.lengthSavingAccountDB() - 1, accID) == -1) {
		cout << "�Է��Ͻ� ���ݰ��°� �������� �ʽ��ϴ�." << endl;
		return;
	}
	else {
		savingAccountIndex = savingAccountDB.searchSavingAccount(0, savingAccountDB.lengthSavingAccountDB() - 1, accID);
	}
	cout << "���� �Ⱓ�� �ۼ����ּ��� : ";
	cin >> date;
	double rate = savingAccountDB.getRate(savingAccountIndex);
	int savingMoney = savingAccountDB.getMoney(savingAccountIndex);

	if (date < savingAccountDB.getDate(savingAccountIndex)) {
		cout << "�ߵ����� �� �ߵ����� ������ ����˴ϴ�." << endl;
		isEarlyCancle = true;
	}
	if(isEarlyCancle)  {
		rate *= 0.1;    // �ߵ������� ���� �������� 10%�� ����  
	}

	for (int i = 1; i <= date; i++)
	{
		total += savingMoney + (savingMoney * (rate / 100.0) * (i / 12.0));  // �ܰ� ���� �����߰�
	}
	cout << date << "���� ���� �� ���� �� " << total << " ���� ������ �� �ֽ��ϴ�." << endl;
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
