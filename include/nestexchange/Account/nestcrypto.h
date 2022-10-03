#ifndef _NEST_CRYPTO_
#define _NEST_CRYPTO_

#include <string>

namespace NestExchange {

	class NestCrypto
	{
		public:
		static std::string cryptPassword(const std::string key,const std::string salt = "");
		static bool compareHash(const std::string hash1, const std::string hash2);
	};

}
#endif
