#ifndef __CELL_H__
#define __CELL_H__
#include "object.h"

class Cell{
	char type;
	int radnum;
	Cell *radius[8];
	Object *p;
	public:
		Cell();
		~Cell();
		void collectRad(Cell *rad);
		void setType(char c);
		Object *getP();
		Object *releaseP();
		Object *findPlay();
		void setP(Object *p);
		bool hasPlayer();
		void printC();
		int canMove();
};
#endif
