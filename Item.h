#ifndef Item_H
#define Item_H
#include <iostream>

using namespace std;

class Item {
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
