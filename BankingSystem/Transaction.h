
#ifndef _TRANSACTION_H
#define _TRANSACTION_H
#include <string>
#include "Account.h"
#include "DebitAccount.h"
#include "CreditAccount.h"

//#include <boost\date_time\gregorian\gregorian.hpp>
#include "date.h"

//using namespace boost::gregorian;

class Transaction
{
public:
	
	// ----------------------------------------------------------------------------------------- // 
	// Constructors / Destruction

	Transaction (int id, double amount, int customerId, date dt)
	{
		_id = id; 
		_amount = amount; 
		_customerId = customerId; 
		_date = dt;
	}

	// ----------------------------------------------------------------------------------------- // 
	// behaviours

	virtual void execute() = 0;
	virtual void rollback() = 0;

	// ----------------------------------------------------------------------------------------- // 
	// getters

	int getId(){return _id;}
	double getAmount(){return _amount;}
	int getCustomerId(){return _customerId;}
	date getDate(){return _date;}

	// ----------------------------------------------------------------------------------------- // 

protected:

	// ----------------------------------------------------------------------------------------- // 
	// data members

	int _id;
	double _amount;
	int _customerId;
	date _date;

	// ----------------------------------------------------------------------------------------- // 

};

#endif
