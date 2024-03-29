#pragma once
#include "account.h"

class CreditAccount : public Account
{
public:

	// -------------------------------------------------------------------------------------------- //
	// constructors / destructors

	CreditAccount
	(	
		int accountId, int customerId, string accountName,
		double interestRate, double balance = 0
	);

	// -------------------------------------------------------------------------------------------- //
	// behaviours

	virtual void deposit(double amount) throw (TransactionException);
	virtual void applyInterest();

};

