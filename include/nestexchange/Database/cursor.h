#ifndef _CURSOR_
#define _CURSOR_

#include "bson.h"
#include <mongoc/mongoc.h>

namespace NestExchange{
class Cursor
{

	public:
		explicit Cursor(mongoc_cursor_t *cursor):_cursor(cursor){}
		~Cursor(){
			mongoc_cursor_destroy(_cursor);
		}
		const Bson next()const; 
	private:
		mongoc_cursor_t* _cursor;
};
}

#endif
