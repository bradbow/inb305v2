#pragma once
#include "Transaction.h"
#include <string>

using namespace std;

class Withdrawal : public Transaction
{
public:
	 
	// ----------------------------------------------------------------------------------------- // 
	// constructors / destructors

	Withdrawal(int id, double amount, int customerId, date dt, DebitAccount* account);

	// ----------------------------------------------------------------------------------------- // 
	// behaviours
	virtual void execute();
	virtual void rollback();

private:

	// ----------------------------------------------------------------------------------------- // 
	// data members

	DebitAccount* _account;
	double _preTransactionBalance;

	// ----------------------------------------------------------------------------------------- // 
	
};

