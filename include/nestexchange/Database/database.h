
#ifndef NEST_DATABASE_
#define NEST_DATABASE_

#include "../core.h"
#include <optional>
#include <string>
#include <nestexchange/LogManager/log.h>
#include "dbcomponent.h"
namespace NestExchange 
{
	class Database : public DBComponent
	{
		public: 
		Database() = default;
		explicit Database(mongoc_database_t* database, std::string dbName)noexcept;
		~Database()override;

		public:
		mongoc_database_t* GetDatabase(){return _database.value();}
		
		const char* GetName()const override{return _databaseName.c_str();}

		private:
		std::optional<mongoc_database_t*> _database = std::nullopt;
		std::string _databaseName {};
		
	};
}

#endif
