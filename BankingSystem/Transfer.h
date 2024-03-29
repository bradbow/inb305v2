#pragma once
#include "Transaction.h"
#include <string>
using namespace std;

class Transfer : public Transaction
{
public:

	// ----------------------------------------------------------------------------------------- // 
	// constructors / destructors
	
	Transfer
	(
		int id, double amount, int customerId, date dt, 
		Account* toAcc, DebitAccount* fromAcc
	);

	// ----------------------------------------------------------------------------------------- // 
	// behaviours

	virtual void execute();
	virtual void rollback();

	// ----------------------------------------------------------------------------------------- // 

private:

	// ----------------------------------------------------------------------------------------- // 
	// data members

	DebitAccount* _fromAccount;
	Account* _toAccount;
	double _preFromAccountBalance;
	double _preToAccountBalance;

	// ----------------------------------------------------------------------------------------- // 
	
};

