#pragma once
#include "Account.h"
#include "TransactionExceptions.hpp"

class DebitAccount: public Account
{
public:
	
	// -------------------------------------------------------------------------------------------- //
	// constructors / destructors

	DebitAccount
	(
		int accountId, int customerId, string accountName,
		double interestRate, double balance = 0
	);

	// -------------------------------------------------------------------------------------------- //
	// behaviours

	virtual void withdraw(double amount);
	virtual void deposit(double amount) throw (TransactionException);
	virtual void applyInterest();

	// -------------------------------------------------------------------------------------------- //

};

