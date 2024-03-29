// Models a bank customer and contains accessors
// and mutators for customer information. Also
// contains functions for adding and removing accounts
// from a customers list of accounts
// Customer.cpp
#include "Customer.h"
#include <iostream>
#include <iterator>


// constructor
// preconditions: valid customer details passed in
// postcondition: customer created
Customer::Customer(
	int userName,	
	string password,
	string name,
	string address, 
	string phoneNumber) :
		User(userName, password),
			_name(name),
			_address(address),
			_phoneNumber(phoneNumber){}

// destructor
// precondition: none
// postcondition: memory deallocated
Customer::~Customer(void){}


// precondition: none
// postcondition: returns name
string Customer::getName(void){

	return _name;
}
// precondition: valid name passed in
// postcondition: name set
void Customer::setName(string name){

	_name = name;
}
// precondition: none
// postcondition: address returned
string Customer::getAddress(void){

	return _address;
}
// precondition: valid address passed in
// postcondition: address returned
void Customer::setAddress(string address){

	_address = address;
}
// precondition: none
// postcondition: phone no returned
string Customer::getPhoneNumber(void){
	
	return _phoneNumber;
}
// precondition: valid phone no passed in
// postcondition: phone no set
void Customer::setPhoneNumber(string phoneNumber){

	_phoneNumber = phoneNumber;
}
// precondition: none
// postcondition: returns account no's
// as list
set <int> Customer::getAccounts(void){

	return _accounts;
}
// precondition: valid accountID passed in
// postcondition: accountID addded to accounts
bool Customer::addAccount(int accountID){

	_accounts.insert(accountID);
	return true;
}
// precondition: valid accountID passed in
// postcondition: accountID removed from accounts
// list
bool Customer::removeAccount(int accountID){

	// TODO Jeff: does this throw error if not in set?
	_accounts.erase(_accounts.find(accountID));
	return true;
}
// precondition: none
// postcondition: returns true if accountID is listed
// in accounts, otherwise false
bool Customer::hasAccount(int accountID){

	//TODO Jeff: add iterator code here
	return true;
}
// precondition: none
// postcondition: returns true if accounts is not empty
bool Customer::hasAcocunt(void){

	return !_accounts.empty();
}

string Customer::operator<< (const Customer &rhs){

	Customer temp = rhs;
	string delimited =
		temp.getUserId() + "," +
		temp._password + "," +
		temp._name + "," +
		temp._phoneNumber + ",";
		set<int> accounts = temp.getAccounts();
		set<int>::iterator iter;
		for(iter = accounts.begin(); iter != accounts.end(); ++iter){
		
			delimited += *iter + ";";
		}
		return delimited += "," + NUM_FIELDS;
}
