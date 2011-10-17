#include "Withdrawal.h"


// ----------------------------------------------------------------------------------------- // 
// constructors / destructors

Withdrawal::Withdrawal
(
	int id, double amount, int customerId, 
	date dt, DebitAccount* account
) : Transaction(id, amount, customerId, dt)
{
	
	_account = account;
	_preTransactionBalance = account->getBalance();

}

// ----------------------------------------------------------------------------------------- // 
// behaviours

void Withdrawal::execute()
{
	_account->withdraw(_amount);
}

void Withdrawal::rollback()
{
	_account->setBalance(_preTransactionBalance);
}