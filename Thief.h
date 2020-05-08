#pragma once
#pragma once
#ifndef Theif_H
#define Thief_H
#include<iostream>
#include"hpps/NPC.h"
#include<fstream>

using namespace std;
class Theif : NPC{
private:
	string type;
public:
	int ahp = 0;
	int aw = 0;
	int ah = 0;
	void setType(bool a) {
		if (a = true) {
			type = "Thief ";
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
		file << " Thief Npc|" << "Hp:" << ahp << "| Hight: " << ah << " | Widht: " << aw << endl;
		file.close();

		aw = 0;
		ah = 0;
		

	}

};
#endif
