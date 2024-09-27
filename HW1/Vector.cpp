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
  vec_ptr = NULL;
  vec_size = 0;
  vec_capacity = 0;
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
  vec_ptr = NULL;
  vec_size = 0;
  vec_capacity = 0;
}

Vector::Vector(const Vector &other){
  vec_size = other.vec_size;
  vec_capacity = other.vec_capacity;
  vec_ptr = new int[vec_capacity];
  for (int i = 0; i < vec_size; i++){
    vec_ptr[i] = other.vec_ptr[i];
  }
}

Vector& Vector::operator=(const Vector &other){
  if (this != &other){
    delete[] vec_ptr;
    vec_ptr = new int[vec_capacity];
    vec_capacity = other.vec_capacity;
    for (int i = 0; i < vec_size; i++){
      vec_ptr[i] = other.vec_ptr[i];
    }
  }
  return * this;
}

void Vector::push_back(int element){
  reserve(vec_size + 1);
  vec_ptr[vec_size++] = element; 
}

void Vector::reserve(int n){
  if (n > vec_capacity){
    int new_capacity;

    if (vec_capacity == 0){
      new_capacity = 1;
    } else {
      new_capacity = vec_capacity * 2;
    }

    int * new_ptr = new int[new_capacity];
    if (vec_ptr != NULL){
      for (int i = 0; i < vec_size; i++){
	new_ptr[i] = vec_ptr[i];
      }
    }

    delete[] vec_ptr;
    vec_ptr = new_ptr;
    vec_capacity = new_capacity;
  }
}

int& Vector::operator[](unsigned int index){
  return vec_ptr[index];
}

int Vector::size(){
  return vec_size;
}

int Vector::capacity(){
  return vec_capacity;
}
