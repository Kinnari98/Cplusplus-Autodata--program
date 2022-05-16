#include "Auto.h"

Auto::Auto() : mBrand("None"), mModel("Nonen"), mGear("None"), mFuel("Nonen"), mAge(0), mLicense("None")
{
	cout << "Auto default constructor called" << endl;
}

Auto::Auto(string aBrand, string aModel, string aGear, string aFuel, int aAge, string aLicense)
	: mBrand(aBrand), mModel(aModel), mGear(aGear), mFuel(aFuel), mAge(aAge), mLicense(aLicense)
{
	cout << "Data added!" << endl;
	cout << endl;
}

Auto::~Auto()
{
	cout << "Vehicle belonging to plate number " << getLicense() << " deleted!" << endl;
}

string Auto::getBrand()
{
	return mBrand;
}

string Auto::getModel()
{
	return mModel;
}

string Auto::getGear()
{
	return mGear;
}

string Auto::getFuel()
{
	return mFuel;
}

int Auto::getAge()
{
	return mAge;
}

string Auto::getLicense()
{
	return mLicense;
}

void Auto::setBrand(string aBrand)
{
	this->mBrand = aBrand;
}

void Auto::setModel(string aModel)
{
	this->mModel = aModel;
}

void Auto::setGear(string aGear)
{
	this->mGear = aGear;
}

void Auto::setFuel(string aFuel)
{
	this->mFuel = aFuel;
}

void Auto::setAge(int aAge)
{
	this->mAge = aAge;
}

void Auto::setLicense(string aLicense)
{
	this->mLicense = aLicense;
}

void Auto::printData()
{
	cout << "\n----------\n";
	cout << "Brand: " << getBrand() << endl;
	cout << "Model: " << getModel() << endl;
	cout << "Transmission: " << getGear() << endl;
	cout << "Fuel: " << getFuel() << endl;
	cout << "Manufacturing year: " << getAge() << endl;
	cout << "License plate number: " << getLicense() << endl;
	cout << "----------\n";
}


