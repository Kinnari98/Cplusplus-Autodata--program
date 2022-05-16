#pragma once
#include <algorithm>

class AutoSingleton {
public:
	static AutoSingleton* getInstance();
	int getData();
	void addAuto(int vectorSize);


private:
	AutoSingleton();
	int carsInVector = 0;
	static AutoSingleton* instance;
};
