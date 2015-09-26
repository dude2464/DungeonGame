//character.h
#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include "potion.h"
#include "object.h"

class Character: public Object{
	//int hp;
	//int atk;
	//int def;
	//char race;
	int cur_hp;
	int effect_atk;
	int effect_def;
	int cur_atk();
	int cur_def();
	int x, y;
public:
	int hp;
	int atk;
	int def;
	char race;
	Character(int hp, int atk, int def, char race);
	void diminishEffect();
	bool slain();
	virtual bool attackability();
	virtual bool usability();
	virtual bool selectability();
	virtual void attack(Character &op);
	virtual void defend(int op_atk);
	virtual void use(Potion &potion);
	virtual void movePiece(int x, int y);
	char retRace();
	int retX();
	int retY();
	virtual ~Character()=0;
};

#endif
