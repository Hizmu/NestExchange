#ifndef _CONFIG_
#define _CONFIG_

#include <string>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace NestExchange {
namespace pt = boost::property_tree;
class Config
{
	public:
		static const std::string GetConnectionString(void) noexcept{
			pt::ptree root;
			pt::read_json(configPath.data(),root);
											
			return root.get<std::string>("connectionpath");
		}
	private:
		static constexpr std::string_view configPath = "../dbconfig.json";

};

}
#endif
