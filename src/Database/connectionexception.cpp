#include "connectionexception.h"

ConnectionException::ConnectionException(const bson_error_t& error)noexcept
	:errorCode(error.code),domain(error.domain),errorFormat("ERROR %1% DOMAIN %2% :%3%")
	{
		errorFormat % errorCode % domain % error.message;
		messageError = std::string_view(errorFormat.str());
	}


const char* ConnectionException::what()const noexcept
{
	return  messageError.c_str();
}
