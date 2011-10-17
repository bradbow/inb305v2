#include "Utils.h"
#include <iostream>
#include "TextFileDataSource.h"
#include "ApplicationController.h"
#include "UserServices.h"
#include "AccountServices.h"
#include <vector>
using namespace std;

ApplicationController* ApplicationController::_ac = NULL;

int main()
{
	// data source
	string fileNames [8] = 
	{
		"Customers.txt", "BankClerks.txt", "SavingsAccounts.txt", "CreditAccounts.txt", 
		"HomeLoanAccounts.txt", "WithdrawalTransactions.txt", "DepositTransactions.txt", 
		"TransferTransactions.txt"
	};
	TextFileDataSource* ds = TextFileDataSource::getInstance();
	ds->setFileNames(fileNames);

	// create services
	UserServices* us = UserServices::instance();
	AccountServices* as = AccountServices::instance();

	// link services to data source
	us->setDataSource(ds);
	as->setDataSource(ds);

	// create controller, add services and launch application
	ApplicationController* ac = ApplicationController::getInstance();
	ac->setAccountService(as);
	ac->setUserService(us);

	//ac->launch();

}