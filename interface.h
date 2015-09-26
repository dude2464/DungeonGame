//interface.h
#ifndef __INTERFACE_H__
#define __INTERFACE_H__
#include <string>
#include "floor.h"
#include "player.h"

class Interface {
	const std::string mapName;
	const int maxLvl;
	int curLvl;
	Floor **gFloors;
	Player *player;
	std::string action;

	bool rightDir(std::string cmd);
	void display();
	void wipeFloors();
public:
	Interface(std::string map_name, int maxLvl = 5);
	~Interface();
	bool gameOver();
	void turn_play();
	void printScore();
};

#endif