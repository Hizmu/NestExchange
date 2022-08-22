#include "collection.h"

namespace NestExchange {


	Collection::Collection(std::optional<mongoc_collection_t*> collection,std::string name):_collection(collection),_collectionName(name){

	}
	Collection::~Collection(){
		if(_collection != std::nullopt){
		mongoc_collection_destroy(_collection.value());
		}
	}
	
	void Collection::InsertOne(const Bson* document){
		NEST_INFO("Insert to colletion");
		if(_collection.has_value()){
			bson_error_t error;

			if(!mongoc_collection_insert_one(
				_collection.value(),
				document->GetDocument(),
				nullptr,
				nullptr,
				&error))
			{
				NEST_ERROR("SEND ERROR : {}",error.message);
			}
		}
	}
	Collection* operator<<(Collection* collection, const Bson& document){
		collection->InsertOne(&document);	
		return collection;
	}
}
