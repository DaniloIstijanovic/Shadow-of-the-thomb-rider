#ifndef Realic_H
#define Realic_H
#include <iostream>
#include "hpps/Item.h"

using namespace std;

class Realic : Item
{
private:
	
	string type;

public:
	void setType(int y) {
		switch (y) {

		case 1:
			type = "Statue";
			break;

		case 2:
			type = "Tiara";
			type = "Necklaces";
			break;

		case 3:
			type = "Necklaces";
			break;
		default:
			cout << "Ne postoji takav realic";
			break;
		}
	}
	
	string getType() {
		return type;
	}
	
};

#endif 