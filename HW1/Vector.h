/**
 *
 *@file Vector.g
 *@author Zack Rippee
 *@date 2024-09-26
 *@brief Vector Class Header
 *
 *The header file for the self made Vector class
 */

#ifndef VECTOR_H
#define VECTOR_H
#include <fstream>
#include <iostream>

class Vector{
 private:
  int * vec_ptr;
  int vec_size, vec_capacity;
 public:
    Vector();
    Vector(const Vector &other);
    ~Vector();
    Vector& operator=(const Vector &other);
    int size();
    int capacity();
    void push_back(int element);
    void reserve(int n);
    int& operator[](unsigned int index);
};
#endif
