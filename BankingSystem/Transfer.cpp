#include "Transfer.h"

// ----------------------------------------------------------------------------------------- // 
// constructors / destructors

Transfer::Transfer
(
	int id, double amount, int customerId, 
	date dt, Account* toAcc, DebitAccount* fromAcc
) : Transaction(id, amount, customerId, dt)
{
	
	_toAccount = toAcc;
	_fromAccount = fromAcc;
	_preFromAccountBalance = _fromAccount->getBalance();
	_preToAccountBalance = _toAccount->getBalance();

}

// ----------------------------------------------------------------------------------------- // 
// behaviours

void Transfer::execute()
{
	_fromAccount->withdraw(_amount);
	_toAccount->deposit(_amount);
}

void Transfer::rollback()
{
	_toAccount->setBalance(_preToAccountBalance);
	_fromAccount->setBalance(_preFromAccountBalance);
}


