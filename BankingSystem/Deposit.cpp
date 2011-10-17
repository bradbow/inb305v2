#include "Deposit.h"

// ----------------------------------------------------------------------------------------- // 
// Constructors / Destructors

Deposit::Deposit
(
	int id, double amount, int customerId, 
	date dt, Account* account
) : Transaction(id, amount, customerId, dt)
{
	 _account = account;
	 _preTransactionBalance = account->getBalance();
}

// ----------------------------------------------------------------------------------------- // 
// behaviours

void Deposit::execute()
{
	_account->deposit(_amount);
}

void Deposit::rollback()
{
	_account->setBalance(_preTransactionBalance);
}



