#include "Functions.h"
#include <algorithm>

Auto AddNewCar()
{
	string brand, model, gear, fuel, license;
	
	
	cout << "Brand?";
	cin >> brand;
	cout << "Model?";
	cin >> model;
	cout << "Transmission?";
	cin >> gear;
	cout << "Fuel?";
	cin >> fuel;
	cout << "Manufacturing year?";
	int age = errorCheck();
	cout << "License plate number?";
	cin >> license;

	return { brand, model, gear, fuel, age, license };
}



string StringToLower(string input)
{
	string newInput = input;
	transform(newInput.begin(), newInput.end(), newInput.begin(), ::tolower);
	return newInput;
}

void searchEngine(bool search, string &license)
{
	if (search) {
		cout << "Data found!\n";
	}
	else {
		cout << "Data not found!\n";
	}
}



int errorCheck()
{
	int value = 0;
	cin >> value;
	while (!cin.good()) {
		cout << "Error!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Input requires a number: ";
		cin >> value;
	}
	return value;
}


