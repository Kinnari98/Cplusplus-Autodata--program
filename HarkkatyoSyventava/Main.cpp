#include <iostream>
#include "Functions.h"
#include "Auto.h"
#include "AutoSingleton.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;


// Subroutine to print out the app menu
void printMenu() {
	cout << "1. Add" << endl;
	cout << "2. Delete" << endl;
	cout << "3. Print data" << endl;
	cout << "4. Search cars" << endl;
	cout << "5. Exit" << endl;
	cout << endl;
}



int main() {
	// Declaration of variables
	int choice;
	string brand, model, gear, fuel, license;
	int age;
	string deleteCar;
	vector<shared_ptr<Auto>> cars;
	AutoSingleton* singleton = AutoSingleton::getInstance();
	char answer;
	string searchLicense;
	bool dataSearched = false;
	


	// Welcoming text / Application starts
	cout << "Welcome to Autodata APP!" << endl;
	cout << "Select whether you'd like to add cars, delete cars or print out data." << endl;
	cout << endl;


	// --------------------------------------------------
	// --------------------------------------------------


	do {
		printMenu();
		choice = errorCheck();
		switch (choice) {
		case 1:
			cout << "Brand?" << endl;
			cin >> brand;
			cout << "Model?" << endl;
			cin >> model;
			cout << "Transmission?" << endl;
			cin >> gear;
			cout << "Fuel?" << endl;
			cin >> fuel;
			cout << "Manufacturing year?" << endl;
			age = errorCheck();
			cout << "License plate number?" << endl;
			cin >> license;
			cars.push_back(make_shared<Auto>(brand, model, gear, fuel, age, license));
			singleton->addAuto(cars.size());
			break;

		case 2:
			cout << "Provide the license plate number of the car, you'd like to remove." << endl;
			cin >> deleteCar;

			deleteCar = StringToLower(deleteCar);
			for (auto &i: cars) {
				if (StringToLower(i->getLicense()) == deleteCar) {
					cars.erase(find(cars.begin(), cars.end(), i));
					break;
				}
			}

			break;

		case 3:
			cout << "Do you wish to sort the data by the license plate number? y/n" << endl;
			cin >> answer;
			if (answer == 'y') {

				// Sorts the data by the license plate number alphabetically.
				sort(cars.begin(), cars.end(), [](const shared_ptr<Auto>& a, const shared_ptr<Auto>& b) {
					return a->getLicense() < b->getLicense();
					});
				if (singleton->getData() == 0) {
					cars.clear();
					cout << "NO DATA ADDED" << endl;
					cout << endl;
					break;
				}
				cout << "\nData sorted by the license plate number alphabetically\n";
				cout << "\n------CARS------\n";
				for (auto&& car : cars) {
					car->printData();
				}
			}
			if (answer == 'n') {
				if (singleton->getData() == 0) {
					cars.clear();
					cout << "NO DATA ADDED" << endl;
					cout << endl;
					break;
				}
				cout << "\nCars are in default order.";
				cout << "\n------CARS------\n";
				for (auto&& car : cars) {
					
					car->printData();
				}

			}
			
			break;

		case 4:
			cout << "Give the license plate number of the car, you'd like to find: ";
			cin >> searchLicense;
			searchLicense = StringToLower(searchLicense);
			for (auto& i : cars) {
				if (StringToLower(i->getLicense()) == searchLicense) {
					dataSearched = true;
					searchEngine(dataSearched, searchLicense);
					i->printData();
					break;
				}
			}
			searchEngine(dataSearched, searchLicense);
			dataSearched = false;
			break;

		case 5:
			cars.clear();
			cout << "Exiting.." << endl;
			 Sleep(4000);
			 cout << "Exit successfull";

		}
	} while (choice != 5);
	




}


