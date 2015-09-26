#ifndef __DRAGONHOARD_H__
#define __DRAGONHOARD_H__

#include "treasure.h"

class DragonHoard: public Treasure {
	bool lockedDown;
	int neighbors_x[8];
	int neighbors_y[8];
public:
	DragonHoard();
	bool pickable();
	void lockOff();
	void move(int x, int y);
	bool withinrad(int x, int y);
	~DragonHoard();
};

#endif
