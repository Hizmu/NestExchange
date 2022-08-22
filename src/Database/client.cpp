#include "client.h"
#include "connectionexception.h"
#include "../LogManager/log.h"
#include "database.h"
#include <memory>
#include <optional>
namespace NestExchange {

	Client::Client(const std::string_view& conn )noexcept:_connectString(std::move(conn))
	{
		mongoc_init();

	}
	
	Client::~Client()
	{
		if(_client != nullptr){
			mongoc_client_destroy(_client);
		}
	}
	void Client::SetConnectionString(const std::string&& conn)noexcept
	{
		if(!conn.empty()){
			_connectString = conn.c_str();
		}
	}

	const char* Client::GetName()const {

		return _connectString.c_str();
	}

	std::shared_ptr<Database> Client::GetDatabase(const std::string &&databaseName)noexcept
	{
		mongoc_database_t* database = mongoc_client_get_database(_client,databaseName.c_str());
		if(database){
			return std::shared_ptr<Database>(new Database(database,databaseName));
		}
		NEST_ERROR("Database doesn't created");
		return nullptr;
	}
	std::shared_ptr<Collection> Client::GetCollection(std::shared_ptr<Database> db,const std::string &&collectionName)noexcept
	{
		NEST_INFO(db->GetName());
		mongoc_collection_t* collection = mongoc_client_get_collection(_client,db->GetName(),collectionName.c_str());
		if(collection)
		{
			return std::shared_ptr<Collection>(new Collection(collection,collectionName));
		}
		NEST_ERROR("Collection doesn't created");
		return nullptr;
	}
	void Client::Connection()
	{
		mongoc_uri_t* uri = CreateUri();			
		if(uri)
		{
			_client = CreateClient(uri);
		}
	}
	
	mongoc_uri_t* Client::CreateUri()noexcept 
	{

		bson_error_t error;
		mongoc_uri_t* uri;
		NEST_INFO(GetName());
		uri = mongoc_uri_new_with_error(GetName(),&error);

		if(!uri)
		{
			NEST_ERROR("Connection Error {} :Invalid connection uri. Change connection uri in dbconfig.json or use default uri  {}",error.code,error.message);
			return nullptr;
		}
		return uri;
	}
	mongoc_client_t* Client::CreateClient(mongoc_uri_t * uri) 
	{
		mongoc_client_t* client;
		bson_error_t error;
		client = mongoc_client_new_from_uri_with_error(uri,&error);

		if(!client)
		{
			NEST_ERROR("Connection ERROR {} : {}",error.code,error.message);
		}
		mongoc_uri_destroy(uri);
		return client;
	}

}
