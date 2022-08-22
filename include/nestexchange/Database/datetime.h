#ifndef NEST_DATATIME
#define NEST_DATATIME
#include <boost/date_time/posix_time/posix_time_config.hpp>
#include <boost/date_time/posix_time/posix_time_io.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <sstream>
namespace NestExchange {
class DateTime
{
	public:
	DateTime(boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time() ){
		static std::locale loc(std::cout.getloc(),
				new boost::posix_time::time_facet("%Y-%m-%dT%H:%M:%SZ"));
		std::stringstream ss;
		ss.imbue(loc);
		ss << boost::posix_time::microsec_clock::universal_time();
		formatTime = ss.str();
	}
	~DateTime()=default;
	std::string Get(){
		return formatTime;
	}
	private:
	std::string formatTime;
};
}

#endif
