#ifndef NEST_COLLECTION_
#define NEST_COLLECTION_
#include "../core.h"
#include "bson.h"
#include "dbcomponent.h"
namespace NestExchange{


	class Collection : public DBComponent
	{
		public:
			Collection()= default;
			explicit Collection(std::optional<mongoc_collection_t*> collection,std::string name);	
			 ~Collection()override;
		public:
			
			bool InsertOne(const Bson* document);
			Bson Find(const Bson* filter);
			Bson Find(const std::string filter);
			Bson Find(const Bson* filter, const Bson* options);
			Bson Find(const std::string filter, const std::string options);
			const char* GetName()const override {
				return _collectionName.c_str();
			}
			
			std::string GetError()const;
			
		private:
				
			std::optional<mongoc_collection_t*> _collection;
			std::string _collectionName;
			bson_error_t _error;
			friend Collection* operator<<(Collection* collection, const Bson& document);
	};



	}

#endif
