#include "interface.h"
#include <iostream>
#include <iomanip>
#include "playerfactory.h"
#include "character.h"
using namespace std;

bool Interface::rightDir(string cmd) {
	return (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" ||
			cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw");
}

void Interface::display() {
	gFloors[curLvl]->printFloor();
	cout << "Race: ";	
	player->retRace();
	cout<<endl;
	cout << "   Gold: " ;
	player->retGold(); 
	cout << endl;
	cout << setw(54) << "Floor " << curLvl + 1 << endl;
	cout << "HP: ";
	player->retHP();
	 cout << endl;
	cout << "Atk: " ;
	player->retAtk(); 
	cout<<endl;
	cout << "Def: " ;
	player->retDef(); 
	cout << endl;
	cout << "Action: " << action << endl;
}

Interface::Interface(string mapName, int maxLvl) : mapName(mapName), maxLvl(maxLvl), curLvl(0), action("Game Start!") {
	gFloors = new Floor*[maxLvl];
	for(int i=0; i < maxLvl; i++) {
		gFloors[i] = new Floor(mapName);
	}
	PlayerFactory pFactory;
	char race='S';
	cout << "Choose your race! ('S'hade, d'R'ow, 'V'ampire, 'T'roll, 'G'oblin): "; 
	cin >> race;
	player = pFactory.createPlayer(race);

	gFloors[curLvl]->init(player);

	display();
}

Interface::~Interface() {
	wipeFloors();
	delete[] gFloors;
	delete player;
}

void Interface::wipeFloors() {
	for(int i=0; i < maxLvl; i++) {
		delete gFloors[i];
	}
}

bool Interface::gameOver() {
	if(maxLvl <= curLvl || player->slain()) {
		return true;
	}
	else {
		return false;
	}
}

void Interface::turn_play() {
	bool valid_cmd = false;
	while(!valid_cmd) {
		string cmd;
		cout << "What is your next movement?: ";
		cin >> cmd;
		if(cmd == "u") {				
			string dir;
			cin >> dir;
			if(rightDir(dir)) {
				if(gFloors[curLvl]->usePotion(dir)) {
					action = "You used a potion.";
				} else {
					action = "This is an invalid movement.";
				}
				gFloors[curLvl]->check();
				valid_cmd = true;
			} else {
				action = "Invalid.";
			}
		}
		else if(cmd == "a") {		
			string dir;
			cin >> dir;
			if(rightDir(dir)) {
				if(gFloors[curLvl]->attackEnemy(dir)) {
					action = "You attacked an enemy.";
				} else {
					action = "Cannot attack.";
				}
				gFloors[curLvl]->check();
				valid_cmd = true;
			} else {
				action = "Invalid command.";
			}
			valid_cmd = true;
		}
		else if(rightDir(cmd)) {		
			int go_up = gFloors[curLvl]->movePlayer(cmd);
			if(go_up == 3) {		
				curLvl++;
				if(curLvl < maxLvl) {	
					gFloors[curLvl]->init(player);
					action = "You went one floor up.";
				}
				else {	
					return;
				}		
			} else {
				if(go_up == 2) {	
				action = "You picked up gold.";	
				} else if(go_up == 1) {		
				action = "You moved.";	
				} else {	
				action = "Cannot move.";	
				}
				gFloors[curLvl]->check();	
			}
			valid_cmd = true;
		}
		else if(cmd == "r") {		
			wipeFloors();
			for(int i=0; i < maxLvl; i++) {
				gFloors[i] = new Floor(mapName);
			}
			curLvl = 0;
			gFloors[curLvl]->init(player);
			action = "Game has been restarted";
			valid_cmd = true;
		}
		else if(cmd == "q") {		
			player->defend(200000);
			return;
		}	
		else {
			action = "Invalid command.";
		} 
	}

	display();
}

void Interface::printScore() {
	cout << "/ ************************************************************************** /" << endl;
	cout << setw(45) << right << "GAME OVER" << endl;
	cout << "/ ************************************************************************** /" << endl;
	cout << setw(48) << right << "Score: ";
	player->retGold();
	cout << endl;
	cout << "/ ************************************************************************** /" << endl;
}
