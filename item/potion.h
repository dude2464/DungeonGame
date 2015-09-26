#ifndef __POTION_H__
#define __POTION_H__
#include <string>
#include "item.h"

class Potion: public Item {
	std::string type;
	int value;
	bool hp;
	bool atk;
	bool def;
	public:
		Potion(std::string type, int value);
		bool usability();
		bool selectability();
		std::string getType();
		int getEffect();
		~Potion();
};
#endif
