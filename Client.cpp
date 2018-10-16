/*
 * Author name: Francois Mukaba
 * Created on: Oct 6, 2018
 * Course: CS 300
 *
 * 									Assignment 1/ Test.cpp
 * */

#include "Contact.h"
#include "Phonebook.h"
#include <iostream>

using namespace std;

int main() {
	//Initialize the Phonebook
	Phonebook directory("Phonebook.txt");
	//Run the application
	directory.application();
	return 1;
}
// Method to Launch the Phonebook Application
void application(Phonebook directory) {
	//Prompt
	cout << "                   Phonebook Application started..." << endl;
	cout << "Please enter: " << endl;
	cout << "	- 'A' to create a contact " << endl;
	cout << "	- 'S' to search a contact" << endl;
	cout << "	- 'D' to delete a contact" << endl;
	cout << "	- 'L' to see a list of your contacts" << endl;
	cout << "	- 'Q' to quit the application" << endl;

	string input = "";
	while (input != "Q") {  //Quit application if input equals Q
		cin >> input;

		//DELETE: delete contacts from storage
		if (input == "D") {
			string name;
			int check;
			cout << "Enter Name: ";
			cin.get();
			getline(cin, name);
			check = directory.remove(name); // the remove method has a bug...put a bunch of cout in it to debug the issue
			if (check == 1) {
				cout << "Contact deleted successfully !" << endl;
			} else {
				cout << "Contact not found in Phonebook !" << endl;
			}
		}

		// SEARCH: search contacts in the storage and returns their number
		else if (input == "S") {
			string name;
			long number;
			cout << "Enter Name: ";
			cin.get();
			getline(cin, name);
			number = directory.search(name);
			if (number == -987654321) {
				cout << "Contact not found in phonebook !" << endl;
			} else {
				cout << "Phone Number: ";
				cout << number << endl;
			}
		}

		//ADD: add into storage contacts that user inputs
		else if (input == "A") {
			string name;
			cout << "Enter Name: ";
			cin.get();
			getline(cin, name);
			cout << "Phone Number: ";
			long number = directory.forceInputType_long();
			directory.add(name, number);
			cout << "Contact added successfully !" << endl;
		}

		//QUIT : stop the application
		else if (input == "Q") {
			continue;
		}

		//LIST: list all contacts in storage
		else if (input == "L") {
			directory.list();
		}

		//Prompt for wrong input
		else {
			cout << "Invalid input, try again..." << endl;
		}
	}
}
