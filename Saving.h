#pragma once
#include "SavingItemCatalogue.h"
#include "SavingAccountDB.h"
#include "AccountDB.h"

class Saving
{
private:
	SavingItemCatalogue saveArr;
	SavingAccountDB savingAccountDB;
public:
	Saving();
	void doSaving(AccountDB ADB);
	void withdraw(AccountDB ADB);
	void setSavingItemCatalogue();
	void changeSavingItemCatalogue();
	void showAllSavingItemCatalogue();
};
