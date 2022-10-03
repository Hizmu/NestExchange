#pragma once



#ifdef WIN64
	#ifdef MSC_VER
		#ifdef NEST_BUILD_DLL
			#define NEST_API __declspec(dllexport)
		#else 
			#define NEST_API __declspec(dllimport)	
		#endif
	 #endif
#elif WIN32
#error Windows 32 not supported

#elif __GNUC__
	#ifdef NEST_BUILD_DLL
		#define NEST_API __attribute__((visibility("default")))
	#else
		#define NEST_API 
	#endif
#else 
	#define NEST_API
	#error Unknow dynamic link symatic
#endif


#include <memory>
#include <string>
#include <string_view>
#include <bson/bson.h>
#include <algorithm>
#include <mongoc/mongoc.h>
#include <sstream>
#include <memory.h>
#include <exception>
#include <spdlog/spdlog.h>
#include <variant>
#include <optional>
#include <boost/json.hpp>
#include "nestexchange/LogManager/log.h"
