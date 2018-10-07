/*
 * Author name: Francois Mukaba
 * Created on: Oct 6, 2018
 * Course: CS 300
 *
 * 									Assignment 1/ Phonebook.cpp
 * */
#include "Phonebook.h"
#include "Contact.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
//create a Phonebook storage of capacity equal to incrementor
Phonebook::Phonebook() {
	storage = new Contact[incrementor];
}
//create and initialize a phonebook with data from which name is the parameter
Phonebook::Phonebook(string fileName) {
	storage = new Contact[incrementor];
	ifstream file(fileName); // input the file in a ifstream object
	string line;
	while (getline(file, line)) { //goes line by line in the file
		string firstName;
		string lastName;
		string temp;
		long number;
		stringstream stream(line);
		getline(stream, firstName, ' '); // read from where it 'points' until it reaches a space and store the chunk
		getline(stream, lastName, ' ');
		getline(stream, temp); // read from where it 'points' until the end of the line
		istringstream(temp) >> number; //parse/cast into integer
		//create and add the contact retrieved from the line
		Contact contact(firstName + " " + lastName, number);
		add(contact);
	}
}
//checks the capacity of the array and can copy it into a bigger array if necessary
void Phonebook::checkCapacity() {
	if (size == (rebuild * incrementor)) {
		Contact * copyStorage = storage;
		delete storage;
		rebuild++;
		storage = new Contact[rebuild * incrementor];
		for (unsigned int i = 0; i < size; i++) {
			storage[i] = copyStorage[i];
		}
	}
}
//checks if there is contact with a certain name in storage to avoid duplicates
//returns true if found
bool Phonebook::contains(string name) {
	for (unsigned int i = 0; i < size; i++) {
		if (storage[i].getName() == name) {
			return true;
		}
	}
	return false;
}
//add new contact
void Phonebook::add(string name, long number) {
	Contact temp(name, number);
	add(temp);
}
//overload add(string,int)
void Phonebook::add(Contact name) {
	if (!contains(name.getName())) {
		checkCapacity();
		storage[size] = name;
		size++;
	}
}
//prints a list of all contacts in storage
void Phonebook::list() {
	for (unsigned int i = 0; i < size; i++) {
		cout << storage[i] << endl;
	}
}
//search for a particular contact
//return it's phone number
long Phonebook::search(string name) {

	for (unsigned int i = 0; i < size; i++) {
		if (storage[i].getName() == name) {
			return storage[i].getNumber();
		}
	}
	return -987654321;
}
//remove a contact
//return 1 if successful
int Phonebook::remove(string name) {
	if (contains(name) == true) {
		Contact * copyStorage = storage;
		delete storage;
		storage = new Contact[size - 1];
		int j = 0;
		for (unsigned int i = j; i < size - 1; i++) {
			if (copyStorage[j].getName() == name) {
				j++; // copyStorage advance
				i--; // storage points at the same address
			} else {
				storage[i] = copyStorage[j];
				j++;
			}
		}
		size--;
		return 1;
	} else {
		return -1;
	}

}
//Forces user to enter inputs of type long
long Phonebook::forceInputType_long() {
	long number = 0;
	bool check = false;
	while (!check) {
		string temp;
		getline(cin, temp);
		stringstream stream(temp);
		if (stream >> number) {
			check = true;
			break;
		} else {
			cout << "invalid input, try again..." << endl;
		}
	}
	return number;
}

// Method to Launch the Phonebook Application
void Phonebook::application() {
	//Prompt
	cout << "                  Phonebook Application started..." << endl;
	cout << "Please enter: " << endl;
	cout << "	- 'A' to create a contact " << endl;
	cout << "	- 'S' to search a contact" << endl;
	cout << "	- 'D' to delete a contact" << endl;
	cout << "	- 'L' to see a list of your contacts" << endl;
	cout << "	- 'Q' to quit the application" << endl;

	string input = "";
	while (input != "Q") {  //Quit application if input equals Q

		cin >> input;

		//ADD: add into storage contacts that user inputs
		if (input == "A") {
			string name;
			cout << "Name: ";
			cin.get();
			getline(cin, name);
			cout << "Phone Number: ";
			long number = this->forceInputType_long();
			this->add(name, number);
			cout << "Contact added successfully !" << endl;
		}

		// SEARCH: search contacts in the storage and returns their number
		else if (input == "S") {
			string name;
			long number;
			cout << "Enter Name: ";
			cin.get();
			getline(cin, name);
			number = this->search(name);
			if (number == -987654321) {
				cout << "Contact not found in phonebook !" << endl;
			} else {
				cout << "Phone Number: ";
				cout << number;
			}
		}

		//LIST: list all contacts in storage
		else if (input == "L") {
			this->list();
		}
		//DELETE: delete contacts from storage
		else if (input == "D") {
			string name;
			int check;
			cout << "Enter Name: ";
			cin >> name;
			check = this->remove(name);
			if (check == 1) {
				cout << "Contact deleted successfully !" << endl;
			} else {
				cout << "Contact not found in Phonebook !" << endl;
			}
		}

		// QUIT : stop the application
		else if (input == "Q") {
			break;
		}

		// Prompt for wrong input
		else {
			cout << "Invalid input, try again..." << endl;
		}
	}
}
