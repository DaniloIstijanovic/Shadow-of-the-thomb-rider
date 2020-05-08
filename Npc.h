#pragma once
#ifndef NPC_h
#define NPC_h
#include<iostream>

using namespace std;

class NPC {
private:
	string aName;
	int ahp;
	int aw;
	int ah;

public:


	string setName(string an) {
		aName = an;
	}
	void sethp(int hp) {
		ahp = hp;

	}
	void setHight(int h) {

		ah = h;
	}
	void setWidht(int w) {
		aw = w;
	}
	string getName() {
		return aName;
	}
	int getHP() {
		return ahp;
	}
	int getH() {
		return ah;
	}
	int getW() {
		return aw;
	}


};
#endif

