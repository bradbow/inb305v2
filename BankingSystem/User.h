// User.h

#include <string>
using std::string;

#ifndef _USER_H
#define _USER_H 

class User
{
public:

	enum UserType
	{
		BANK_CLERK,
		CUSTOMER
	};

	friend class BankClerk;
	friend class Customer;
	friend class UserServices;
	
	// constructor
	// precondition: valid user details passed in
	// postcondition: user is created
	User(int userId, string password);
	// destructor
	// precondition: none
	// postcondition: memory deallocated
	~User(void);

	int getUserId(){return _userId;}

private:

	int _userId;
	string _password;
	string _userName;
	UserType m_utType;
};
#endif
