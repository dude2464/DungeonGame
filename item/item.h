#ifndef __ITEM_H__
#define __ITEM_H__
#include "object.h"
#include <string>

class Item: public Object {
	public:
		Item(char type);
		virtual bool attackability();
		virtual bool usability()=0;
		virtual bool selectability()=0;
		virtual ~Item()=0;
};
#endif
