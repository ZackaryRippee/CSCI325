

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class Phonebook{
 private:
  struct Entry{
    string first_name;
    string last_name;
    string phone_number;
    Entry* next;
  };
  Entry* head;

 public:
  Phonebook();
  ~Phonebook();

  void push_front(string first_name, string last_name, string phone_number);
  void push_back(string first_name, string last_name, string phone_number);
  void read_from_file(string fileName);
  void write_to_file(string fileName);
  void insert_sorted(string first_name, string last_name, string phone_number);
  void lookup(string name);
  void reverse_lookup(string phone_number);
  void print();
  void delete_user(string name);
};


#endif // PHONEBOOK_H
