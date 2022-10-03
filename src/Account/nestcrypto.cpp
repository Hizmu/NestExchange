#include "nestcrypto.h"
#include <openssl/sha.h>
#include <cstring>
#include <sstream>
#include <iomanip>
namespace NestExchange {

	std::string NestCrypto::cryptPassword(const std::string key,const std::string salt)
	{
		if(key.empty())
			return "";
		const std::string str = key + salt;
		unsigned char hash[SHA256_DIGEST_LENGTH];
		SHA256_CTX sha256;
		SHA256_Init(&sha256);
		SHA256_Update(&sha256, str.c_str(),str.size());
		SHA256_Final(hash,&sha256);
		std::stringstream ss;
		for(unsigned int i = 0; i < SHA256_DIGEST_LENGTH; i++){
			ss<< std::hex << std::setw(2)<< std::setfill('0') << (int)hash[i];
		}
		return ss.str();
	}
	bool NestCrypto::compareHash(const std::string hash1, const std::string hash2){
		if(hash1.size() != hash2.size()){
			return false;
		}
		for(int i = 0; i < hash1.size() && i < hash2.size(); i++){
			if(hash1[i] != hash2[i]){
				return false;
			}
		}
		return true;
	}
}
