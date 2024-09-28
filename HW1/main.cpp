/**
 *
 *@file main.cpp
 *@author Zack Rippee
 *@date 2024-09-27
 *@brief Testing for Vector class
 */
#include <iostream>
#include <fstream>
#include "Vector.h"
using namespace std;



/**
 * main: Runs tests for operator[], size() in a loop , and assignment and copy constructor both showing Deep Copy
 *
 * @pre Vector class
 * @return int return 0 (end program)
 * @post 
 * 
 */
int main(){
  Vector Vec;
  //Tests adding integers into vector, prints out the capacity to test it's doubling
  for (int i = 0; i < 1000; i++){
    Vec.push_back(i);
    cout << "New insert: " << Vec[i] << " Capacity: " << Vec.capacity() << endl;
  }
  cout << endl;

  //Uses Vector Size to print out the Vector
  cout << "Vector One (Vec): " << endl;
  for (int i = 0; i < Vec.size(); i++){
    cout << Vec[i] << endl;
  }
  cout << endl;

  //Assignment Test (Deep Copy)
  Vector VecTwo = Vec;
  //Prints out VecTwo to make sure it assigned properly
  cout << "Vector Two (VecTwo): " << endl;
  for (int i = 0; i < VecTwo.size(); i++){
    cout << VecTwo[i] << endl;
  }
  cout << endl;

  //Using copy constructor
  Vector VecCopy(Vec);  
  cout << "Vector One copy (VecCopy): " << endl;
  //Prints out VecCopy to make sure it copied
  for (int i = 0; i <VecCopy.size(); i++){
    cout << VecCopy[i] << endl;
  }
  cout << endl;
  return 0;
}
