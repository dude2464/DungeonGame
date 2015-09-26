#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include "character.h"
#include "treasure.h"

class Player: public Character{
	int gold;
	public:
		Player(int hp, int atk, int def, char race);
		virtual void pickUpG(Treasure &gold);
		void retGold();
		void retRace();
		void retHP();
		void retAtk();
		void retDef();
		virtual ~Player()=0;
		
};
#endif
