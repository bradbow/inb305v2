#include "Withdrawal.h"

Withdrawal::Withdrawal
(
	Identifier<int> id, double amount, int customerId, 
	date dt, int accountId
) : Transaction(id, amount, customerId, dt)
{
	
	_accountId = accountId;

}

void Withdrawal::execute()
{

}