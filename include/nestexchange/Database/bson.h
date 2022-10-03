#ifndef NEST_BSON_
#define NEST_BSON_
#include "../core.h"
#include "nestexchange/LogManager/log.h"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <cstddef>

namespace NestExchange{
	class Bson
	{
		public:	

			Bson()=default;
			Bson(Bson&bson):_document(bson._document){}
			Bson(bson_t* bson):_document(bson){}
			~Bson() 
			{
				if(_document != nullptr){
					bson_destroy(this->_document);
				}
			}

			void CreateBsonFromJson(std::string json)noexcept
			{
				std::string js;
				std::swap(js,json);
				bson_error_t error;
				this->_document = bson_new();
				if(!bson_init_from_json(_document, 
							js.c_str()
							,-1,&error))
				{
					NEST_ERROR("CreateBsonFromJson ERROR {}: {}",error.code,error.message);
					this->_document = nullptr;
					return;
				}
					NEST_INFO("Bson Created");
				
			}
			static const std::string JsonFromBson(Bson bson){
				size_t len;
				if(bson.GetDocument()){
					return bson_as_relaxed_extended_json(bson.GetDocument(),&len);
				}
				return "";
			}
			const std::string JsonFromBson(){
				return Bson::JsonFromBson(this->_document);	
			}
			static std::string GetValue(std::string json, std::string value){
				std::stringstream ss(json);
				boost::property_tree::ptree pt;
				boost::property_tree::read_json(ss,pt);
				return pt.get<std::string>(value);	
			}
			const std::string GetValue(std::string value){
				return Bson::GetValue(this->JsonFromBson(),value);
			}
			bson_t* GetDocument()const{return _document;}
		private:
			bson_t* _document = nullptr;
	};
}
#endif
