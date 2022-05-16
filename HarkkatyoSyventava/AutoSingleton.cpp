#include "AutoSingleton.h"

AutoSingleton* AutoSingleton::instance = nullptr;

int AutoSingleton::getData() {
	return carsInVector;
}

AutoSingleton* AutoSingleton::getInstance() {
	if (instance == nullptr) {
		instance = new AutoSingleton();
	}
	return instance;
}

AutoSingleton::AutoSingleton() {
	carsInVector = 0;
}

void AutoSingleton::addAuto(int vectorSize) {
	carsInVector = vectorSize;
}
