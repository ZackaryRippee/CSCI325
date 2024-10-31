//phonebook.cpp

#include "phonebook.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Phonebook::Phonebook(){
  head = NULL;
}

Phonebook::~Phonebook(){
  Entry* current = head;
  while (current != NULL){
    Entry * temp = current;
    current = current->next;
    delete temp;
  }
}

void Phonebook::push_front(string first_name, string last_name, string phone_number){
  Entry* new_entry = new Entry;
  new_entry->first_name = first_name;
  new_entry->last_name = last_name;
  new_entry->phone_number = phone_number;
  new_entry->next = head;
  head = new_entry;
}

void Phonebook::push_back(string first_name, string last_name, string phone_number){
  Entry* new_entry = new Entry;
  new_entry->first_name = first_name;
  new_entry->last_name = last_name;
  new_entry->phone_number = phone_number;
  new_entry->next = NULL;
  
  if (head == NULL){
    head = new_entry;
    return;
  }
  
  Entry* current = head;
  while (current->next != NULL){
    current = current->next;
  }
  current->next = new_entry;
}

void Phonebook::read_from_file(string fileName){
  ifstream file(fileName);
  if (!file.is_open()){
    cout << "Failed to open file: " << fileName << endl;
    return;
  }

  string first_name, last_name, phone_number;
  while (file >> first_name >> last_name >> phone_number){
    push_back(first_name, last_name, phone_number);
  }

  file.close();
  cout << "File successfully loaded" << fileName << endl;
}

void Phonebook::write_to_file(string fileName){
  ofstream file(fileName);
  if (!file.is_open()){
    cout << "Failed to open file for writing: " << fileName << endl;
    return;
  }

  Entry* current = head;
  while (current != NULL){
    file << current->first_name << " " << current->last_name << " " << current->phone_number << endl;
  }
}

void Phonebook::insert_sorted(string first_name, string last_name, string phone_number){
  Entry* new_entry = new Entry;
  new_entry->first_name = first_name;
  new_entry->last_name = last_name;
  new_entry->phone_number = phone_number;
  
  if (head == NULL || head->last_name > last_name){
      new_entry->next = head;
      head = new_entry;
      return;
   }

  Entry* current = head;
    while (current->next != NULL && current->next->last_name < last_name){
      current = current->next;
    }
    new_entry->next = current->next;
    current->next = new_entry;
}


 void Phonebook::lookup(string last_name){
   Entry* current = head;
   int check = 0;
   while (current != NULL){
     if (current->last_name == last_name){
     cout << last_name << "'s phone number: " << (*current).phone_number << endl;
     check = 1;
     break;
     }
     current = current->next;
   }

   if (check == 0){
     cout << last_name << "'s number could not be found." << endl;
   }
 }

 void Phonebook::reverse_lookup(string phone_number){
   Entry* current = head;
   int check = 0;

   while (current != NULL){
     if (current->phone_number == phone_number){
       cout << phone_number << ": belongs to " << current->first_name << " " << current->last_name << "." << endl;
       check = 1;
       break;
     }
     current = current->next;
   }

   if (check == 0){
     cout << "No name linked to " << phone_number << "." << endl;
   }
 }

 void Phonebook::print(){
   Entry* current = head;

   if (current == NULL){
     cout << "Nothing is in the phonebook!" << endl;
     return;
   }

   cout << "First Name |" << " Last Name" << endl << "Phone-Number" << endl;

   while (current != NULL){
     cout << current->first_name << " " << current->last_name << endl << current->phone_number << endl;

     current = current->next;
   }
 }

 void Phonebook::delete_user(string name){
   if (head == NULL){
     cout << "Nothing is in the phonebook!" << endl;
     return;
   }

   if (head->first_name == name || head->last_name == name){
     Entry* temp = head;
     head = head->next;
     delete temp;
     cout << name << "'s number was deleted." << endl;
     return;
   }

   Entry* current = head;
   while (current->next != NULL){
     if (current->next->first_name == name || current->next->last_name == name){
       Entry* temp = current->next;
       current->next = current->next->next;
       delete temp;
       cout << name << "'s number was deleted." << endl;
       return;
     }
     current = current->next;
   }

   cout << name << "'s number wasn't found." << endl;
       
 }

     
