#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <string>
#include "cell.h"
#include "player.h"
#include "treasure.h"
#include "potion.h"
#include "enemy.h"

class Floor {
	std::string name;
	int width;
	int height;
	Cell **cells;
	static std::string defaultFloor;
	Player *player;
	int goldnum;
	int potionnum;
	int enemynum;
	static int max_gold;
	static int max_potion;
	static int max_enemy;
	Treasure **treasures;
	Potion **potions;
	Enemy **enemies;
	bool onFloor(int i, int j);
	void addRad(int i, int j);
	void changeCoor(int x, int y, std::string dir);
	void getRandPos(int x, int y);
	public:
		Floor(std::string name, int width=79, int height=25);
		~Floor();
		void init(Player *player);
		void check();
		int movePlayer(std::string dir);
		bool usePotion(std::string dir);
		bool attackEnemy(std::string dir);
		void printFloor();
};
#endif
