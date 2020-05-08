#ifndef Oruzje_H
#define Oruzje_H
#include <iostream>

using namespace std;

class Oruzje{
private:
	int id;
	int W;
public:
	void setId(int id2) {
		id = id2;
	}
	void setIW(int We) {
		W = We;
	}
	int getId() {
		return id;
	}
	int getIW() {
		return W;
	}

};

#endif 