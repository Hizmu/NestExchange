#ifndef NEST_COLLECTION_
#define NEST_COLLECTION_
#include "../core.h"
#include <nestexchange/LogManager/log.h>
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
			
			void InsertOne(const Bson* document);
			const char* GetName()const override {
				return _collectionName.c_str();
			}

		private:
			std::optional<mongoc_collection_t*> _collection;
			std::string _collectionName;

			friend Collection* operator<<(Collection* collection, const Bson& document);
	};



	}

#endif
