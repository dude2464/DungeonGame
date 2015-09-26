//main.cc
#include <string>
#include <iostream>
#include "interface.h"
using namespace std;

int main(int argc, char *argv[]) {
	//cout<<"1";
	string floorplan = (argc == 2)? argv[1] : "default.txt";
	//cout<<"2";
	Interface main_game(floorplan);
	
	while(!main_game.gameOver()) {
		main_game.turn_play();
	}
	main_game.printScore();

	return 0;
}
