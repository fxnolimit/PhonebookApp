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