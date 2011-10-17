#pragma once
#include "DataSource.h"
#include "AccountServices.h"
#include "UserServices.h"

class ApplicationController
{
public:
	
	static ApplicationController* getInstance()
	{
		if (_ac = NULL)
		{
			_ac = new ApplicationController();
		}

		return _ac;
	}

	static void setUserService(UserServices* us){_us = us;}
	static void setAccountService(AccountServices* as){_as = as;}

private:  

	ApplicationController(){}

	static ApplicationController* _ac;
	static UserServices* _us;
	static AccountServices* _as;

};

