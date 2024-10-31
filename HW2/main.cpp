/**
 *
 *@file main.cpp
 *@author Zack Rippee
 *@date 2025-10-29
 *@brief main file for phonebook
 */


#include "phonebook.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
  Phonebook phonebook;
  int choice = 0;
  string fileName, name, phoneNumber, firstName, lastName;

  cout << "Welcome to the UTM Phonebook!" << endl;

  while (choice != 8){
    cout << "Please choose an option:" << endl;
    cout << "1. Read a phonebook from a file" << endl << "2. Write the phonebook to a file" << endl << "3. Print the phonebook" << endl
	 << "4. Search for a user's phone number" << endl << "5. Reverse lookup by phone number" << endl << "6. Add a user" << endl
	 << "7. Delete a user" << endl << "8. Exit this program" << endl << "Enter your choice: ";
    cin >> choice;

    if (choice == 1){
      cout << "Enter file name: ";
      cin >> fileName;
      phonebook.read_from_file(fileName);
    }
    else if (choice == 2){
      cout << "Enter file name: ";
      cin >> fileName;
      phonebook.write_to_file(fileName);
    }
    else if (choice == 3){
      phonebook.print();
    }
    else if (choice == 4){
      cout << "Enter last name to search for a phone number: ";
      cin >> name;
      phonebook.lookup(name);
    }
    else if (choice == 5){
      cout << "Enter phone number to search for a user: ";
      cin >> phoneNumber;
      phonebook.reverse_lookup(phoneNumber);
    }
    else if (choice == 6){
      cout << "Enter first name: ";
      cin >> firstName;
      cout << "Enter last name: ";
      cin >> lastName;
      cout << "Enter phone number: ";
      cin >> phoneNumber;
      phonebook.push_back(firstName, lastName, phoneNumber);
    }
    else if (choice == 7){
      cout << "Enter the name (first or last) of the user to remove: ";
      cin >> name;
      phonebook.delete_user(name);
    }
    else if (choice == 8){
      cout << "Exiting program." << endl;
      break;
    }
    else {
      cout << "Please enter a number between 1 and 8." << endl;
    }
    
  }
  return 0;
}
