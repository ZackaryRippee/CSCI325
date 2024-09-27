# file: makefile 
# Name: Zackary Rippee
# Date: 2024-09-23
# brief: makefile for make & makefile assignment
#

CC = g++

CFLAGS = -g -Wall -Wextra

TARGET = test

deafult: all

all: main.o Vector.o
	$(CC) $(CFlags) -o $(TARGET) main.o Vector.o

Vector.o: Vector.cpp Vector.h
	$(CC) $(CFLAGS) -c Vector.cpp

main.o:
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) $(TARGET) *.o *~
