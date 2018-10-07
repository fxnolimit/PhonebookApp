/*
 * Author name: Francois Mukaba
 * Created on: Oct 6, 2018
 * Course: CS 300
 *
 * 									Assignment 1/Contact.h
 * */

#ifndef CONTACT_H_
#define CONTACT_H_
#include <iostream>
using namespace std;

class Contact {
private:
	string fullName; //contact's name
	long number; //contact's phone number
public:
	//default constructor
	Contact() {
		fullName = " ";
		number = 0;
	}
	//create Contact with name and phoneNum from parameters
	Contact(string name, long phoneNum) {
		fullName = name;
		number = phoneNum;

	}
	//rename a contact
	void rename(string newName) {
		fullName = newName;
	}
	//change a contact's phone number
	void edit(long phoneNum) {
		number = phoneNum;
	}
	//accessors
	string getName() {
		return fullName;
	}

	int getNumber() {
		return number;
	}
	//operator << overload to allow printing contacts
	friend ostream& operator<<(ostream& os, const Contact & contact) {
		os << contact.fullName << ' ' << contact.number;
		return os;
	}
};

#endif

