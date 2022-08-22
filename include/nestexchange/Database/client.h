
#ifndef NEST_CLIENT_
#define NEST_CLIENT_

#include "../core.h"
#include "database.h"
#include "collection.h"

namespace NestExchange {

class Client : public DBComponent
{

	public:
		Client(const std::string_view& connectionString = _default_connectString)noexcept;
		~Client() override;
	public :
		void SetConnectionString(const std::string&& connectionString)noexcept;
		const char* GetName()const override;
		[[nodiscard]]std::shared_ptr<Database> GetDatabase(const std::string&& databaseName)noexcept;
		[[nodiscard]]std::shared_ptr<Collection>GetCollection(std::shared_ptr<Database> db, const std::string&& collectionName)noexcept;
		void Connection() ;
	private:
		mongoc_uri_t* CreateUri()noexcept ;
		mongoc_client_t* CreateClient(mongoc_uri_t * uri) ;
	private:
		static constexpr std::string_view _default_connectString = "mongodb://127.0.0.1/" ;
		std::string _connectString = {};
		mongoc_client_t* _client = nullptr;
};

}
#endif
