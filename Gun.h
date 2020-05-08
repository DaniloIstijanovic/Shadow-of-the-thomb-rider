#pragma once
#ifndef Gun_H
#define Gun_H
#include "hpps/Oruzje.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class Gun : Oruzje
{
private:
	string type;
	int range;
	int dps;
	int magazine;
	int dmg;
public:
	void setType(int a) {
		cin >> a;
		switch (a) {
		case 1:
			type = "Pistol";
			range = 130;
			dps = 30;
			dmg = 60;
			break;
		case 2:
			type = "Rifle";
			range = 210;
			ats = 50;
			dmg = 100;
			break;
		case 3:
			type = "Sniper";
			range = 400;
			ats = 15;
			dmg = 190;
			break;

		default:
			cout << "Ne postoji takav Mac";
			break;
		}
	}
	string getType() {
		return type;
	}
	int getRange() {
		return range;
	}
	int getAttackSpeed() {
		return ats;

	}
};

#endif 
