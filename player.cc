#include <string>
#include <iostream>
#include "player.h"
using namespace std;

Player::Player(int hp, int atk, int def, char race): Character(hp, atk, def, race), gold(0){}

	void Player::pickUpG(Treasure &g){
		this->gold += g.getAmt();
		if(this->race == 'G'){
			this->gold += 5;
		}
	}
	
	void Player::retGold(){
		cout << this->gold;
	}

	void Player::retRace(){
		if(this->race == 'S') {
			cout << "Shade";
		}
		else if(this->race == 'R') {
			cout << "Drow";
		}
		else if(this->race == 'V') {
			cout << "Vampire";
		}
		else if(this->race == 'T') {
			cout << "Troll";
		}
		else if(this->race == 'G') {
			cout << "Goblin";
		}

	}
	void Player::retHP(){
		cout << hp;
	}
	void Player::retAtk(){
		cout << atk;
	}
	void Player::retDef(){
		cout << def;
	}
	
	Player::~Player(){}
