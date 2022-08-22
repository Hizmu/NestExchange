#ifndef NEST_DBCOMPONENT_
#define NEST_DBCOMPONENT_

#include <string>

class DBComponent
{
	public:
	virtual ~DBComponent() = default; 
	virtual const char* GetName()const = 0;

};


#endif
