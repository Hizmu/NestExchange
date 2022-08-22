#ifndef _APPLICATION_
#define _APPLICATION_
#include "../core.h"
#include "../Account/accountmanager.h"
#include "../Database/client.h"
#include "../LogManager/LogManager.h"
#include "../LogManager/log.h"
#include <memory>
#include <iostream>
#include <string>


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
