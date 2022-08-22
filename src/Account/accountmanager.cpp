#include "accountmanager.h"
#include "accountdata.h"
#include "datetime.h"
#include "nestexchange/LogManager/log.h"
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/format.hpp>
#include <bson/bson.h>
#include <memory>
#include <nestexchange/Database/datetime.h>

namespace NestExchange {
		AccountManager::AccountManager(std::shared_ptr<Collection> col):collection(col){}
	
	void AccountManager::Registration(AccountData&& data,std::string passwd)
	{
		if(data.GetEmail().empty()|| data.GetLogin().empty()||data.GetPhoneNumber().empty()){
			if(data.GetEmail().empty()){
				NEST_ERROR("Email empty");
			}
			if(data.GetLogin().data()){
				NEST_ERROR("Login empty");
			}
			if(data.GetPhoneNumber().data()){
				NEST_ERROR("PhoneNumber empty");
			}
			return;
		}
		Bson newAccount = CreateRegistrationBson(data,passwd);
		
		collection.get() << newAccount;
		
		NEST_INFO("Account sended");

		}

	void AccountManager::SetCollection(std::shared_ptr<Collection>other)
	{
		collection = other;
	}
	Bson AccountManager::CreateRegistrationBson(AccountData& data, std::string passwd){

			Bson bson;
			DateTime* time = new DateTime();
			bson.CreateBsonFromJson(
					(
						boost::format("{           \
										\"login\": \"%1%\", \
									    \"email\": \"%2%\", \
									    \"mobile\": \"%3%\", \
									    \"password\": \"%4%\", \
										\"registrationdate\": { \"$date\": \"%6%\" } ,\
										\"lastlogindate\": { \"$date\": \"%6%\" } \
									   }")
						%data.GetLogin()%data.GetEmail()%data.GetPhoneNumber()%passwd.c_str()%time->Get()%time->Get()
						).str()
					);
			return bson;
		}
	}
