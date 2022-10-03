#include "database.h"

namespace NestExchange
{


	Database::Database(mongoc_database_t* db,std::string dbName)noexcept: _database(db),_databaseName(std::move(dbName)){}

	Database::~Database(){
		if(_database != std::nullopt){
			mongoc_database_destroy(_database.value());	
		}
	}

}
