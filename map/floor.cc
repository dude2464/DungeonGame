#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "floor.h"
#include "character.h"
#include "object.h"
#include "itemFactory.h"
#include "enemyfactory.h"
#include "enemy.h"
using namespace std;

string Floor::defaultFloor="default.map";
int Floor::max_gold=10;
int Floor::max_potion=10;
int Floor::max_enemy=20;

Floor::Floor(string name, int width, int height): 
	name(name),width(width), height(height),player(0),goldnum(max_gold),potionnum(max_potion),enemynum(max_enemy){
		treasures= new Treasure *[goldnum];
		potions= new Potion *[potionnum];
		enemies = new Enemy *[enemynum];
		cells=new Cell *[height];
		for(int i=0; i<goldnum; ++i){
			treasures[i]=0;
		}
		for(int i=0; i< potionnum; ++i){
			potions[i]=0;
		}
		for(int i=0; i<enemynum; ++i){
			enemies[i]=0;
		}
		for(int i=0; i<height; ++i){
			for(int j=0; j<width; ++j){
				addRad(i, j);
			}
		}
		ifstream floorplan;
		floorplan.open(name.c_str());
		for(int i=0; i<height; ++i){
			string row;
			getline(floorplan, row);
			for(int j=0; j<width; ++j){
				cells[i][j].setType(row[j]);
			}
		}
}

Floor::~Floor(){
	for(int i=0; i<goldnum; ++i){
		if(treasures[i])
			delete treasures[i];
	}
	for(int i=0; i<potionnum; ++i){
                if(potions[i])
                        delete potions[i];
        }
	for(int i=0; i<enemynum; ++i){
                if(enemies[i])
                        delete enemies[i];
        }
	for(int i=0; i<height; ++i){
		delete [] cells[i];
	}
	delete [] treasures;
	delete [] potions;
	delete [] enemies;
	delete [] cells;
}

bool Floor::onFloor(int x, int y){
	return (x>=0) &&
		(x<=height)&&
		(y>=0)&&
		(y<=width);
}

void Floor::addRad(int x, int y){
	if(onFloor(x-1, y)){
		cells[x][y].collectRad(&cells[x-1][y]);
	}
	if(onFloor(x, y+1)){
                cells[x][y].collectRad(&cells[x][y+1]);
        }
	if(onFloor(x+1, y)){
                cells[x][y].collectRad(&cells[x+1][y]);
        }
	if(onFloor(x, y-1)){
                cells[x][y].collectRad(&cells[x][y-1]);
        }
	if(onFloor(x-1, y+1)){
                cells[x][y].collectRad(&cells[x-1][y+1]);
        }
	if(onFloor(x+1, y+1)){
                cells[x][y].collectRad(&cells[x+1][y+1]);
        }
	if(onFloor(x+1, y-1)){
                cells[x][y].collectRad(&cells[x+1][y-1]);
        }
	if(onFloor(x-1, y-1)){
                cells[x][y].collectRad(&cells[x-1][y-1]);
        }
}


void Floor::getRandPos(int x, int y){
        do{
                x=rand()%(width-2)+1;
                y=rand()%(height-2)+1;
        } while(cells[y][x].canMove() != true);
}

void Floor::changeCoor(int x, int y, string direction){
	if(direction=="ea"){
		++x;
	}
	else if(direction=="so"){
		++y;
	}
	else if(direction=="we"){
		--x;
	}
	else if(direction=="no"){
		--y;
	}
	else if(direction=="se"){
		++x;
		++y;
	}
	else if(direction=="nw"){
		--x;
		--y;
	}
	else if(direction=="sw"){
		--x;
		++y;
	}
	else{
		++x;
		--y;
	}
}

void Floor::init(Player *player) {
	if(name != defaultFloor) {
	} 
	else {
		int x=0;
		int y=0;
		srand(time(0));
		getRandPos(x, y);
		cells[y][x].setType('/');
		ItemFactory f;
		for(int i=0; i<goldnum; i++) {
			int type = rand() % 8;
			if(type <= 6) {
				if(type <= 4) {
					treasures[i] = dynamic_cast<Treasure *>(f.generateItem(6));
				} 
				else {
					treasures[i] = dynamic_cast<Treasure *>(f.generateItem(7));
				}
				getRandPos(x, y);
				treasures[i]->movePiece(x, y);	
				cells[treasures[i]->retY()][treasures[i]->retX()].setP(treasures[i]);
			}
			else{
				treasures[i] = dynamic_cast<Treasure *>(f.generateItem(9));
				getRandPos(x, y);
				treasures[i]->movePiece(x, y);
				EnemyFactory e;
				for(int j=0; i<enemynum; i++) {
					if(!enemies[j]) {
						enemies[j] = e.generateEnemy('D', treasures[i]);
						int randx, randy, dragonx, dragony;
						do {
							randx = rand()%3-1;
							randy = rand()%3-1;
							dragonx = treasures[i]->retX() + randx;
							dragony = treasures[i]->retY() + randy;
						} while(cells[dragony][dragonx].canMove() != 1);
						enemies[j]->movePiece(dragonx, dragony);
					}
				}
			}
		}
		for(int i=0; i<potionnum; i++) {
			int type = rand() % 6;
			potions[i] = dynamic_cast<Potion *>(f.generateItem(type));
			getRandPos(x, y);
			potions[i]->movePiece(x, y);
			cells[potions[i]->retY()][potions[i]->retX()].setP(potions[i]);
		}

		EnemyFactory e;
		for(int i=0; i<enemynum; i++) {
			if(!enemies[i]) {
				char type;
				int r = rand() % 18;
				if(r <= 3) {
					type = 'H';
				} else if(r <= 6) {
					type = 'W';
				} else if(r <= 11) {
					type = 'L';
				} else if(r <= 13) {
					type = 'E';
				} else if(r <= 15) {
					type = 'O';
				} else {
					type = 'M';
				}
				enemies[i] = e.generateEnemy(type);
				getRandPos(x, y);
				enemies[i]->movePiece(x, y);
				cells[enemies[i]->retY()][enemies[i]->retX()].setP(enemies[i]);
			}
		}
		this->player = player;
		player->diminishEffect();
		getRandPos(x, y);
		player->movePiece(x, y);
		cells[player->retY()][player->retX()].setP(player);
	}
}

void Floor::check() {
	for(int i=0; i<enemynum; i++) {
		if(enemies[i] && !enemies[i]->slain()) {
			int ex = enemies[i]->retX();
			int ey = enemies[i]->retY();
			if(enemies[i]->hostility() && cells[ey][ex].findPlay()) {
				Player *target = dynamic_cast<Player *>(cells[ey][ex].findPlay());
				enemies[i]->attack(*target);
			} 
			else {
				int randx, randy, x, y;
				do {
					randx=rand()%3-1;
					randy=rand()%3-1;
					x=ex+randx;
					y=ey+randy;
				} while(cells[y][x].canMove()!=1 || !enemies[i]->withinrad(x, y));
				enemies[i]->movePiece(x, y);
				cells[ey][ex].releaseP();
				cells[enemies[i]->retY()][enemies[i]->retX()].setP(enemies[i]);
			}
		}
	}
}

int Floor::movePlayer(string direction) {
	int r=0;
	int x=player->retX();
	int y=player->retY();
	changeCoor(x, y, direction);
	if(cells[y][x].canMove() >= 1 && cells[y][x].canMove() <= 4) {		
		if(cells[y][x].canMove() == 3) {
			r=3;
		} 
		else if(cells[y][x].canMove() == 4) {
			player->pickUpG(*dynamic_cast<Treasure *>(cells[y][x].getP()));
			for(int i=0; i<goldnum; i++) {
				if(treasures[i] == cells[y][x].getP()) {
					delete treasures[i];
					treasures[i]=0;
					break;
				}
			}
			cells[y][x].releaseP();
			r=2;
		} else {
			r=1;
		}
		cells[player->retY()][player->retX()].releaseP();
		player->movePiece(x, y);
		cells[player->retY()][player->retX()].setP(player);
	} else {
		r=0;
	}
	return r;
}

bool Floor::usePotion(string direction) {
	int x = player->retX();
	int y = player->retY();
	changeCoor(x, y, direction);
	Object *t = cells[y][x].getP();
	if(t && t->usability()) {
		player->use(*dynamic_cast<Potion *>(t));
		for(int i=0; i<potionnum; i++) {
			if(potions[i] == t) {
				delete potions[i];
				potions[i]=0;
				break;
			}
		}
		cells[y][x].releaseP();
		return true;
	} else {
		cout << "Can't be used!" << endl;
		return false;
	}
}

bool Floor::attackEnemy(string direction) {
	int x = player->retX();
	int y = player->retY();
	changeCoor(x, y, direction);
	Object *t = cells[y][x].getP();
	if(t && t->attackability()) {
		player->attack(*dynamic_cast<Enemy *>(t));
		if(dynamic_cast<Enemy *>(t)->slain()) {
			Treasure *item = dynamic_cast<Enemy *>(t)->dropGold();
			if(item) {
				player->pickUpG(*item);
				delete item;
			}
			for(int i=0; i<enemynum; i++) {
				if(enemies[i] == t) {
					delete enemies[i];
					enemies[i]=0;
					break;
				}
			}
			cells[y][x].releaseP();
		}
		return true;
	} else {
		cout << "Can't be attacked!" << endl;
		return false;
	}
}

void Floor::printFloor() {
	for(int i=0; i<height; i++) {
		for(int j=0; j<width; j++) {
			cells[i][j].printC();
		}
		cout << endl;
	}
}
