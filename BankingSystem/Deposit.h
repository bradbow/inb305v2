#pragma once
#include "Transaction.h"
#include "Account.h"

class Deposit : public Transaction
{
public:

	// ----------------------------------------------------------------------------------------- // 
	// Constructors / Destructors

	Deposit(int id, double amount, int customerId, date dt, Account* account);
	
	// ----------------------------------------------------------------------------------------- // 
	// behaviours

	virtual void execute();
	virtual void rollback();

private:

	// ----------------------------------------------------------------------------------------- // 
	// data members

	Account* _account;
	double _preTransactionBalance;

	// ----------------------------------------------------------------------------------------- // 

};

