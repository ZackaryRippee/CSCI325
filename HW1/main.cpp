
#include <iostream>
#include <fstream>
#include "Vector.h"
using namespace std;

int main(){
  Vector Vec;
  //Tests adding integers into vector, prints them out
  for (int i = 0; i < 1000; i++){
    Vec.push_back(i);
    cout << Vec.capacity() << endl;
  }

  //Uses Vector Size to print out the Vector
  for (int i = 0; i < Vec.size(); i++){
    cout << Vec[i] << endl;
  }
  cout << endl;

  //Copying Vector to a Second one
  Vector VecTwo;
  VecTwo = Vec;

  
  

  return 0;
}
