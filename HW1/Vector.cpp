/**
 *
 *@file Vector.cpp
 *@author Zack Rippee
 *@date 2024-09-26
 *@brief Vector class
 */


#include "Vector.h"
#include <iostream>
#include <fstream>

using namespace std;



/**
 * Constructor for Vector class, initializes pointer and size/capacity values
 *
 * @param 
 * @pre
 * @return n/a
 * @post vec_ptr is NULL, vec_size and vec_capacity = 0
 * 
 */
Vector::Vector(){
  int * vec_ptr = NULL;
  int vec_size = 0;
  int vec_capacity = 0;
}

/**
 * Deconstructor for Vector class
 *
 * @param
 * @pre
 * @return n/a
 * @post vec_ptr has been deallocated, vec_size and vec_capacity = 0
 *
 */
Vector::~Vector(){
  delete[] vec_ptr;
  int vec_size = 0;
  int vec_capacity = 0;
}

Vector::Vector(const Vector &other){

}

Vector& Vector::operator=(const Vector &other){

}

void Vector::push_back(int element){

}

void Vector::reserve(int n){

}

int& Vector::operator[](unsigned int index){

}

int Vector::size(){
  return vec_size;
}

int Vector::capacity(){
  return vec_capacity;
}
