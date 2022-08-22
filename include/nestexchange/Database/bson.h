#ifndef NEST_BSON_
#define NEST_BSON_
#include "../core.h"
#include <bson/bson.h>
#include <nestexchange/LogManager/log.h>
namespace NestExchange{
	class Bson
	{
		public:	

			Bson()=default;
			Bson(Bson&bson):_document(bson._document){}
			~Bson() 
			{
				if(_document != nullptr){
					bson_destroy(_document);
				}
			}

			void CreateBsonFromJson(std::string json)noexcept
			{
				std::string js;
				std::swap(js,json);
				bson_error_t error;
				_document = bson_new();
				if(!bson_init_from_json(_document, 
							js.c_str()
							,-1,&error))
				{
					NEST_ERROR("CreateBsonFromJson ERROR {}: {}",error.code,error.message);
					_document = nullptr;
					return;
				}
					NEST_INFO("Bson Created");
				
			}
			
			bson_t* GetDocument()const{return _document;}
		private:
			bson_t* _document = nullptr;
	};
}
#endif
