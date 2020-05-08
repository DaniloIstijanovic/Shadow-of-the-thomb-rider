#ifndef Armour_H
#define Armour_H
#include <iostream>
#include "Item.h"

using namespace std;

class Armour : Item
{
private:
	int armour;
	string type;

public:

	void setArmor(int ar) {
		armor = ar;
	}
	void setType(int y) {
		switch (y) {

		case 1:
			type = "West";
			break;

		case 2:
			type = " Riot Shield";
			break;
		}
	}

	int getArmor() {
		return armour;
	}
	string getType() {
		return type;
	}
};

#endif 

