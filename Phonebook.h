/*
 * Author name: Francois Mukaba
 * Created on: Oct 6, 2018
 * Course: CS 300
 *
 * 									Assignment 1/Phonebook.h
 * */

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_
#include "Contact.h"

class Phonebook {
public:
	unsigned const int incrementor = 200000; // to keep consistent memory allocation everytime the array is rebuilt
	unsigned int size = 0; // number of elements in the array
	unsigned int rebuild = 1; // number of time array has been built
	Contact *storage; // array to store the contacts
public:
	Phonebook();
	Phonebook(string);
	long getLength();
	void checkCapacity();
	bool contains(string);
	void add(string, long);
	void add(Contact);
	int remove(string);
	long search(string);
	void list();
	long forceInputType_long();
	void application();

};

#endif
