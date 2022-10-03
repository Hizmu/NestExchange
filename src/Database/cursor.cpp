#include "cursor.h"

namespace NestExchange {

		const Bson Cursor::next()const {
			const bson_t* bson;
			bson_error_t * error;
			mongoc_cursor_next(_cursor,&bson);
			if(mongoc_cursor_error(_cursor, error))
				return Bson(nullptr);
			return Bson((bson_t*)bson);
		}
}
