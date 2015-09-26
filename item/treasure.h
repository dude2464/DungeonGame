//treasure.h

#ifndef __TREASURE_H__
#define __TREASURE_H__
#include "item.h"

class Treasure: public Item{
	int amt;
public:
	Treasure(int amt);
	virtual bool selectability();
	bool usability();
	int getAmt();
	~Treasure();

};

#endif
