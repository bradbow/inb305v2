// AccountServices.h
// Provides services to open, close, retrieve and modify customer 
// accounts.

#include "Account.h"
#include "DebitAccount.h"
#include "DataSource.h"
#include "CreditCardAccount.hpp"
#include "HomeLoanAccount.hpp"

#include <vector>
using namespace std;

#include <string>
using std::string;

#ifndef _ACCOUNT_SERVICES_H
#define _ACCOUNT_SERVICES_H
class AccountServices
{
public:

	enum accountType{ SAVINGS_ACC, CREDIT_ACC, HOME_LOAN_ACC};

	// -------------------------------------------------------------------------------------------- //
	// constructors / destructors / instance retreival

	~AccountServices(void){}

	// precondition: none
	// postcondition: an AccountSerices is returned, if none is alreay
	// available one is created then returned
	static AccountServices *instance(void);

	// -------------------------------------------------------------------------------------------- //
	// behaviours

	// precondition: valid parameters passed in
	// postcondition: a savings account is created and returned
	void makeSavingsAccount 
	(
		string accountName, int customerId,
        double interestRate, double balance
	);

	// precondition: valid parameters passed in
	// postcondition: a credit account is created and returned
	void makeCreditCardAccount 
	(
		string accountName, int customerId,
        double interestRate, double balance,
        double overdraftLimit
	);

	// precondition: valid parameters passed in
	// postcondition: a home loan account is created and returned
	void makeHomeLoanAccount 
	(
		string accountName, int customerId,
        double interestRate, double balance,
        string propertyAddress, HomeLoanAccount::RepaymentOption option, 
        double minimumRepayment
	);

	// precondition: valid accountID with a zero balance is passed in
	// postcondition: account matching accountID is closed 
	void closeAccount(int accountID);

	// precondition: valid accountID passed in
	// postcondition: Account matching accountID returned
	Account *getAccount(int accountID);

	// precondition: valid customerID passed in
	// postcondition: list of accounts matching customerID returned
	vector<Account*> getAccountsForCustomer(int customerID);

	void setDataSource(DataSource* ds){_ds = ds;}

	// -------------------------------------------------------------------------------------------- //

private:

	static AccountServices* _accountServicesInstance;
	static DataSource* _ds;
	
	// precondition: none
	// postcondition: creates instance of AccountServices
	AccountServices(){}	

	// -------------------------------------------------------------------------------------------- //
	// utility

	int getNextAccountId(){return 1;}

};
#endif

