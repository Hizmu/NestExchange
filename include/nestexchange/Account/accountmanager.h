#ifndef _ACCOUNT_MANAGER_
#define _ACCOUNT_MANAGER_

#include "accountdata.h"


#include <memory>
#include <nestexchange/Database/client.h>

#include <string>

namespace NestExchange {
		class AccountManager{
			private:
				using Login = std::string;
				using Email = std::string;
				using PhoneNumber = std::string;
			public:		
				AccountManager(std::shared_ptr<Collection> accountCol);
				~AccountManager() = default;
			public:

				void Registration(AccountData&& data,std::string paswd);
				void Registration(Login&& login, Email&& email,PhoneNumber&& phone, std::string&&  paswd);
				void SignIn(AccountData&& data);
				void SignIn(Login&& login,std::string && passwd);
				void FindAccount();
				void SetCollection(std::shared_ptr<Collection> other);
			private:
				std::shared_ptr<Collection> collection;	
				Bson CreateRegistrationBson(AccountData& data, std::string passwd);
		
		};
	
}
#endif
