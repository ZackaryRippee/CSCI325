CC = g++
CFLAGS = -g -Wall -Wextra

TARGET = bst_word_count

default: all

all: driver.o bst.o
	$(CC) $(CFLAGS) -o $(TARGET) driver.o bst.o

bst.o: bst.cpp bst.h
	$(CC) $(CFLAGS) -c bst.cpp

driver.o: driver.cpp bst.h
	$(CC) $(CFLAGS) -c driver.cpp

clean:
	$(RM) $(TARGET) *.o *~
