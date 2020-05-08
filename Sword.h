#pragma once
#ifndef sword_H
#define sowrd_H
#include "hpps/Oruzje.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class Sword : Oruzje
{
private:
	string type;
	int range;
	int ats;

public:
	void setType(int a) {
		cin >> a;
		switch (a) {
		case 1:
			type = "Knife";
			range = 20;
			ats = 1.2;
			break;
		case 2:
			type = "Sword";
			range = 50;
			ats = 0.7;
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
	int getAtkSpeed() {
		return ats;

	}
};

#endif 