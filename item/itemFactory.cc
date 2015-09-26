#include "itemFactory.h"
#include "treasure.h"
#include "smallhoard.h"
#include "normalhoard.h"
#include "merchanthoard.h"
#include "dragonhoard.h"
#include "potion.h"
using namespace std;

Item *ItemFactory::generateItem(int n) {
	Item *r;
	switch(n) {
	case 0:
		r=new Potion("RH", 10);
		break;
	case 1:
		r=new Potion("BA", 5);
		break;
	case 2:
		r=new Potion("BD", 5);
		break;
	case 3:
		r=new Potion("PH", -10);
		break;
	case 4:
		r=new Potion("WA", -5);
		break;
	case 5:
		r=new Potion("WD", -5);
		break;
	case 6:
		r=new SmallHoard();
		break;
	case 7:
		r=new NormalHoard();
		break;
	case 8:
		r=new MerchantHoard();
		break;
	case 9:
		r=new DragonHoard();
		break;
	default:
		r=0;
		break;
	}
	return r;
}
