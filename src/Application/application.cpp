#include "application.h"
#include <exception>
#include <math.h>
#include <memory>
#include <string>

#include "../config.hpp"
#include "nestexchange/Account/accountdata.h"
#include "nestexchange/Account/accountmanager.h"
#include "nestexchange/LogManager/log.h"


namespace NestExchange {

using std::cout,std::cin,std::string;

Application::Application(){
	_logs.Initialize();
	_client = std::shared_ptr<Client>(new Client());

}

Application::~Application()
{
	_logs.ShutDown();
}

void Application::Sign()
{
	string log{};
	cout << "Enter login :";
	cin >> log;
	string pass {};
	cout << "Enter password :";
	cin >> pass;
	NEST_INFO("Connection to NestDB");
	_client->Connection();
;
	NEST_INFO("Connection to Account");

		
}
void Application::Registaration(){
	string log{};
	cout << "Enter login : ";
	cin >> log;
	string email;
	cout << "Enter email : ";
	cin >> email;	
	cout << "Enter mobile : ";
	string mobile;
	cin >> mobile;
	string pass ;
	cout << "Enter password : ";
	cin >> pass;
	NEST_INFO("Connection to NestDB");


	NEST_INFO("Connection to Account");

	NEST_INFO("Registaration");
	AccountData data(log,email,mobile);
}
void Application::TestRegistration()
{
	cout<<"---------------------------"<<"\n";
	cout<<"     Test Registaration    "<<"\n";
	cout<<"---------------------------"<<"\n";
	string log = "test";
	cout << "Login : " << log<< "\n";
	string email = "test@test.com";
	cout << "Email email : " << email << "\n";
	string mobile = "123456789";
	cout << "Mobile : " << mobile << "\n";
	string pass = "123456789";
	cout << "Password : " << pass << "\n";
	NEST_INFO("Connection to NestDB");
	_client->Connection();
	std::shared_ptr<Database> db = _client->GetDatabase("NestDB");
	NEST_INFO("Connection to Account");
	std::shared_ptr<Collection> account = _client->GetCollection(db,"account");
	_manager = std::shared_ptr<AccountManager>(new AccountManager(account));
	NEST_INFO("Registaration");
	AccountData data(log,email,mobile);
	_manager->Registration(std::move(data),pass);
	NEST_INFO("REGISTRATION OK");
}
int Application::exec(){
		cout<<"---------------------------"<<"\n";
		cout<<"Welcome to the NestExchange"<<"\n";
		cout<<"---------------------------"<<"\n";
	do {
		cout<<"1. Sign In"<< "\n";	
		cout<<"2. Sign Out"<<"\n";
		cout<<"3. Test Registration"<<"\n";
		cout<<"4. Exit"<<"\n";
		unsigned int selected = 0;
		_loginSelector = LoginSelector::NONE;
		string connectString = Config::GetConnectionString().data();
		_client->SetConnectionString(std::move(connectString));
		while(_loginSelector == LoginSelector::NONE){
			cin>> selected;
			_loginSelector = (LoginSelector)selected;
		}

		switch (_loginSelector) {
			case LoginSelector::NONE:
				continue;
			case LoginSelector::REGISTRATION:
				Registaration();	
				break;
			case LoginSelector::TEST_REGISTRATION:
				TestRegistration();
				break;
			case LoginSelector::EXIT_APPLICATION:
				break;
			default:
				continue;
		}	

	}while (_loginSelector != LoginSelector::EXIT_APPLICATION);
	cout<<"---------------------------"<<"\n";
	cout<<"         Good Bye          " <<"\n";
	cout<<"---------------------------"<<"\n";

	return 1;
}




}
