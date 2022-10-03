#include "accountmanager.h"
#include "bson.h"
#include "datetime.h"
#include <boost/container_hash/extensions.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/format.hpp>
#include <boost/format/format_fwd.hpp>
#include "nestcrypto.h"
#include "nestexchange/LogManager/log.h"

namespace NestExchange {
		AccountManager::AccountManager(std::shared_ptr<Collection> col):collection(col){}
	
	void AccountManager::Registration(AccountData&& data,std::string passwd)
	{
		std::string error = "";
		if(data.GetEmail().empty()|| data.GetLogin().empty()||data.GetPhoneNumber().empty()){
			if(data.GetEmail().empty()){
				error += "Email empty ";
			}
			if(data.GetLogin().data()){
				error += "Login empty ";
			}
			if(data.GetPhoneNumber().data()){
				error += "PhoneNumber empty ";
			}
			NEST_ERROR("ERROR " + error);
			return;
		}
		std::string hash = NestCrypto::cryptPassword(passwd,data.GetLogin());
		Bson newAccount = CreateRegistrationBson(data,hash);
		
		collection.get() << newAccount;
			
		if((error = collection->GetError()) != "0"){
				NEST_ERROR(error);
				return;
			}
			NEST_INFO("Account sended");
			return;
		}
	void AccountManager::SignIn(Login &login, std::string &passwd){
		std::string error = "";
		if(login.empty() || passwd.empty()){
			if(login.empty()){
				error += "Login empty ";
			}
			if(passwd.empty()){
				error += "Password empty";
			}
			NEST_ERROR("ERROR "+ error);
		}
		Bson account = FindAccount(login);
		if(!account.GetDocument() ){
			NEST_ERROR("ERROR Login or password not correct");
			return;
		}
			std::string accountPass = account.GetValue("password");
			std::string hashPass = NestCrypto::cryptPassword(passwd,login);
			if(!NestCrypto::compareHash(accountPass,hashPass)){
				NEST_ERROR("ERROR Login or password not correct");
				return;
			}
			NEST_INFO("WELCOME TO NESTEXCHANGE");
	}
	Bson AccountManager::FindAccount(const Login login){
		Bson bson;
		bson.CreateBsonFromJson(
				(
				 boost::format("{ \"login\" : \"%1%\" }"
					 )%login
				).str()
				);
		return collection->Find(&bson);
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
