
#pragma once
#ifndef Citizen_H
#define Citizen_H
#include<iostream>
#include"hpps/NPC.h"
#include<fstream>

using namespace std;
class Citizen : NPC {
private:
	string type;
public:
	int ahp = 0;
	int aw = 0;
	int ah = 0;
	void setType(bool a) {
		if (a = true) {
			type = "Citizen";
		}
		else {

			type = "Dead";
		}

	}
	string getype() {
		return type;
	}

	void printA(int aw, int ah, int ahp) {
		aw = rand() % 50;
		ah = rand() % 200;
		

		ofstream file;
		file.open("assets/NPC.txt");
		file << " Citizen Npc|" <<"| Hight: " << ah << " | Widht: " << aw << endl;
		file << "Citizen nb. 1 :" << endl;
		file << "Hi im a random Citizen" << endl;
		file.close();

		aw = 0;
		ah = 0;
		

	}

};
#endif

