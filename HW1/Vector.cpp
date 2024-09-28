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
  vec_ptr = NULL; //POINTER - points to NULL (safe)
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
  delete[] vec_ptr; //Deallocation of pointer
  vec_ptr = NULL; //POINTER - points to NULL (safe)
  vec_size = 0;
  vec_capacity = 0;
}



/**
 * Copy Constructor: Initializes a dynamic array of the appropriate
 *    size/capacity and copies data from other's array to the new array
 *
 * @pre existing Vector 
 * @return  
 * @post vec_ptr is initialized, and its array contains other.vec_ptr's data,
 *    vec_size=other.vec_size, and vec_capacity=other.vec_capacity.
 * 
 */
Vector::Vector(const Vector &other){
  vec_size = other.vec_size;
  vec_capacity = other.vec_capacity;
  vec_ptr = new int[vec_capacity]; //POINTER - points to new array with capacity 
  for (int i = 0; i < vec_size; i++){
    vec_ptr[i] = other.vec_ptr[i];
   }
}

/**
 * Assignment operator.  Initializes a dynamic array of the appropriate
 *    size/capacity and copies data from other's array to the new array.
 *
 * @pre existing Vector
 * @return 
 * @post  vec_ptr is initialized, and its array contains other.vec_ptr's data,
 *    vec_size=other.vec_size, and vec_capacity=other.vec_capacity.
 * 
 */
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


/**
 * Similar to std::vector.push_back(int element), stores element at the end of the vector.
 * If necessary, calls reserve() before adding element to the end of the vector.
 * @pre existing Vector
 * @return void
 * @post Item element has is stored at the end of the vector.
 * 
 */
void Vector::push_back(int element){
  reserve(vec_size + 1);
  vec_ptr[vec_size++] = element; 
}

/**
 *  Requests that the vector capacity be resized at least enough to contain n elements.
 *
 *    If n is greater than the current capacity, the function causes the container to reallocate
 *    its storage increasing its capacity to n (or greater).
 *
 *    If n is less than or equal to the current capacity, the call does nothing (no reallocation
 *    or change in vector capacity).
 *
 *    This function has no effect on vector size and cannot alter its elements.
 *
 * @pre Existing Vector 
 * @return void
 * @post Vector capacity is now n.  Vector size (and contents) remains the same.
 * 
 */
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


/**
 * Returns a reference to the element at position indexReturns a reference to the element at position index
 *
 * @pre
 * @return element reference at position index
 * @post  
 * 
 */
int& Vector::operator[](unsigned int index){
  return vec_ptr[index];
}

/**
 * Returns the current number of elements in the vector
 *
 * @pre
 * @return int
 * @post  
 * 
 */
int Vector::size(){
  return vec_size;
}

/**
 * Returns the currently allocated storage capacity of the vector.
 *
 * @pre
 * @return int
 * @post  
 * 
 */
int Vector::capacity(){
  return vec_capacity;
}
