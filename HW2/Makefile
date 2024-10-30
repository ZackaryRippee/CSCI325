# file: makeFile 
# Name: Zackary Rippee
# Date: 2024-10-27
# brief: makefile for phonebook
#



CC = g++
CFLAGS = -g -Wall -Wextra

TARGET = phonebook

default: all

all: main.o phonebook.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o phonebook.o

phonebook.o: phonebook.cpp phonebook.h
	$(CC) $(CFLAGS) -c phonebook.cpp

main.o: main.cpp phonebook.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) $(TARGET) *.o *~

