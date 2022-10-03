#include "collection.h"
#include "bson.h"
#include "cursor.h"
#include "nestexchange/Account/account.h"
#include "nestexchange/LogManager/log.h"
#include <boost/format.hpp>

namespace NestExchange {


	Collection::Collection(std::optional<mongoc_collection_t*> collection,std::string name):_collection(collection),_collectionName(name){

	}
	Collection::~Collection(){
		if(_collection != std::nullopt){
		mongoc_collection_destroy(_collection.value());
		}
	}
	
	bool Collection::InsertOne(const Bson* document){
		if(_collection.has_value()){
			bson_error_t error;

			if(!mongoc_collection_insert_one(
				_collection.value(),
				document->GetDocument(),
				nullptr,
				nullptr,
				&error))
			{
				_error = error;
				
				return false;
			}
		}
		return true;
	}

	Bson Collection::Find(const Bson* query)
	{
		Cursor cursor(mongoc_collection_find_with_opts(_collection.value(),query->GetDocument(),nullptr,nullptr));
		Bson bson = cursor.next();
		if(!bson.GetDocument()){
			NEST_ERROR("ERROR Account doesn't found");
			
		}
		return bson;
	}

	Collection* operator<<(Collection* collection, const Bson& document){
		collection->InsertOne(&document);	
		return collection;
	}

	std::string Collection::GetError()const{
		return (boost::format("Error code %1% : %2%")%_error.code%_error.message).str();

	}
}
