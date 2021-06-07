#include "saving.h"
#include "loan.h"
// void Bank::client()함수 작성(예외처리)
// void Bank::BankManager()함수 작성(예외처리)

class Bank {
private:
	AccountDB ADB;
	Saving savingObj;
	loan loanObj;
	int num;
public:
	Bank();
	void setAuthority();	
	void joinAccount();		
	void cancelAccount();	
	void allAccountsPrint();
	void accountPrint();	
	void deposit();			
	void withdraw();		
	void savig();			
	void loan();			

	void client();							
	void BankManager();				
	void savingManager();
	void loanManager();
};
