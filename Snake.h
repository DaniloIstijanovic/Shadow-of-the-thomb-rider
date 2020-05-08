
#pragma once
#ifndef Snake_H
#define Snake_H
#include<iostream>
#include"hpps/Animal.h"
#include<fstream>

using namespace std;
class Snake : Animal {
private:
	string type;
public:
	int ahp;
	int aw;
	int ah;
	void setType(bool a) {
		if (a = true) {
			type = "Wild";
		}
		else {

			type = "Dead";
		}

	}
	string getype() {
		return type;
	}

	void printA(int aw, int ah, int ahp) {
		aw = rand() % 30;
		ah = rand() % 140;
		ahp = aw * 2 + ah;

		ofstream file;
		file.open("assets/Animal.txt");
		file << "Animal:Snake |" << "Hp:" << ahp << "| Hight: " << ah << " | Widht: " << aw << endl;
		file.close();

		aw = 0;
		ah = 0;
		ahp = 0;

	}

};
#endif