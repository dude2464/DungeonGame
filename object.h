#ifndef __OBJECT_H__
#define __OBJECT_H__

class Object{
	char s;
	int x;
	int y;
	public:
		Object(char s);
		int retX();
		int retY();
		virtual void movePiece(int x, int y);
		virtual bool attackability()=0;
		virtual bool selectability()=0;
		virtual bool usability()=0;
		virtual bool isPlayer();
		void ps();
		//~Object();
};
#endif 
