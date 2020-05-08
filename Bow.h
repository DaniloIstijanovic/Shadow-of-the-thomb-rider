
#pragma once
#ifndef Bow_H
#define Bow_H
#include "hpps/Oruzje.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class Bow : Oruzje
{
private:
	string type;
	int range;
	int dps;

public:
	void setType(int a) {
		cin >> a;
		switch (a) {
		case 1:
			type = "Poison";
			range = 200;
			dps = 15;
			break;
		case 2:
			type = "Fire";
			range = 200;
			dps = 17;
			break;

		default:
			cout << "Ne postoji takava strela";
			break;
		}
	}
	string getType() {
		return type;
	}
	int getRange() {
		return range;
	}
	int getDmgPerSecound() {
		return dps;

	}
};

#endif 