
#ifndef _CONNECTION_EXEPTION_
#define _CONNECTION_EXEPTION_

#include "../core.h"
#include <boost/format.hpp>

class ConnectionException : public std::exception
{
public:
	ConnectionException(const bson_error_t& error)noexcept;

	virtual const char* what()const noexcept override;

private:
	unsigned errorCode = 0;
	unsigned domain = 0;
	std::string messageError = "";
	boost::format errorFormat; 
};

#endif
