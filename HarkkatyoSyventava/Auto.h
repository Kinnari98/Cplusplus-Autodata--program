#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Auto {
public:
	Auto();
	Auto(string aBrand, string aModel, string aGear, string aFuel, int aAge, string aLicense);
	~Auto();

	// Getters
	string getBrand();
	string getModel();
	string getGear();
	string getFuel();
	int getAge();
	string getLicense();

	// Setters
	void setBrand(string aBrand);
	void setModel(string aModel);
	void setGear(string aGear);
	void setFuel(string aFuel);
	void setAge(int aAge);
	void setLicense(string aLicense);

	void printData();

private:
	string mModel;
	string mBrand;
	string mGear;
	string mFuel;
	int mAge;
	string mLicense;



};
