#ifndef _APPLICATION_
#define _APPLICATION_
#include "nestexchange/core.h"
#include "nestexchange/Account/accountmanager.h"
#include "nestexchange/Database/client.h"
#include "nestexchange/LogManager/LogManager.h"
#include "nestexchange/LogManager/log.h"


namespace NestExchange {

class  Application
{

	public:
		Application();
	private:
		~Application();
	public:
		void Sign();
		void Registaration(); 
		int exec();		
		void TestRegistration();
	public:
		enum LoginSelector{
				NONE = 0,
				SIGN,
				REGISTRATION,
				TEST_REGISTRATION,
				EXIT_APPLICATION,
				EXIT_ACCOUNT
			};

	private:
		LogManager _logs;
		std::shared_ptr<AccountManager> _manager;
		LoginSelector _loginSelector;
		std::shared_ptr<Client> _client;
	};
}
#endif
