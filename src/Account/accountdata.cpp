#include "accountdata.h"
namespace NestExchange{
AccountData::AccountData(Login login,Email email,PhoneNumber phoneNumber)
	:_login(std::move(login)),
		_email(std::move(email)),
		_phoneNumber(std::move(phoneNumber))
{
}
AccountData::AccountData(AccountData& accountdata)
	:_login(accountdata._login),
	_email(accountdata._email),
	_phoneNumber(accountdata._phoneNumber)
{}

AccountData::AccountData(AccountData&& accountdata):
	_login(std::move(accountdata._login)),
	_email(std::move(accountdata._email)),
	_phoneNumber(std::move(accountdata._phoneNumber)){
	accountdata.Clear();
}

std::string AccountData::GetLogin()const{
	return std::string(_login);
}
std::string AccountData::GetEmail()const{
	return std::string(_email);
}

std::string AccountData::GetPhoneNumber()const{
	return std::string(_phoneNumber);
}


void AccountData::Clear(){
	_email.clear();
	_phoneNumber.clear();
	_login.clear();
	AccountData::~AccountData();
}

AccountData* AccountData::Clone(){
	return new AccountData(*this);
}
}
