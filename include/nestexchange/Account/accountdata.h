#pragma once
#include "../core.h"


namespace NestExchange{

	class AccountData{
		private:
			using Login = std::string;
			using Email = std::string;
			using PhoneNumber = std::string;
			
			Login _login;
			Email _email;
			PhoneNumber _phoneNumber;
			
		public:
			AccountData(Login login,Email email,PhoneNumber phoneNumber);
			AccountData(AccountData& );
			AccountData(AccountData&&);
			~AccountData()=default;


		public:
			Login GetLogin() const;
			Email GetEmail()const;
			PhoneNumber GetPhoneNumber()const;

			void Clear();

			AccountData* Clone();

	};
}
