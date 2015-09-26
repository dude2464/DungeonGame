//playerfactory.h
#ifndef __PLAYERFACTORY__H
#define __PLAYERFACTORY__H

#include "player.h"

class PlayerFactory {
public:
	Player *createPlayer(char c);
};

#endif
