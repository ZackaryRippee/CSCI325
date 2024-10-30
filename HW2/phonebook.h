

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class Phonebook{
 private:
  struct entry{
    string first_name;
    string last_name;
    string phone_number;
    Entry* next
  };
  Entry * head;

 public:
  Phonebook();
  ~Phonebook();

  void push_front(const string& first_name, const string& last_name, const string& phone_number);
  void push_bacl(const string& first_name, const string& last_name, const string& phone_number);
  void read_from_file(const string& fileName);
  void write_to_file(const string& fileName);
  void insert_sorted(const string& first_name, const string& last_name, const string& phone_number);
  void lookup(string& name);
  void print();
  void delete_user(string& name);
};
