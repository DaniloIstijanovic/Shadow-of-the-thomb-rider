#pragma once
#ifndef Deer
#define Deer_H
#include<iostream>
#include"hpps/Animal.h"
#include<fstream>

using namespace std;
class Deer : Animal {
private:
	string type;
public:
	int ahp = 0;
	int aw = 0;
	int ah = 0;
	void setType(bool a) {
		if (a = true) {
			type = "Wild Animal";
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
		ah = rand() % 300;
		ahp = aw * 2 + ah;

		ofstream file;
		file.open("assets/Animal.txt");
		file << "Animal:Deer |" << "Hp:" << ahp << "| Hight: " << ah << " | Widht: " << aw << endl;
		file.close();

		aw = 0;
		ah = 0;
		ahp = 0;

	}

};
#endif
