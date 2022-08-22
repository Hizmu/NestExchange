#ifndef _ACCOUNT_
#define _ACCOUNT_
#include "accountdata.h"
namespace NestExchange {

class Account{
	public:
		Account();
		float GetBalace();
	private:
		float _balance = 0;
};

}

#endif
