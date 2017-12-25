CC = gcc
CFLAGS = -Wall -pedantic -g -std=c99 -Iinclude
BIN = ./bin/
SRC = ./src/
AST = ./assets/

all: program test

program:
	$(CC) $(CFLAGS) $(SRC)main.c $(SRC)linkList.c $(SRC)patient.c $(SRC)queues.c $(SRC)dummy.c -o $(BIN)runMe

test:
	$(CC) $(CFLAGS) $(SRC)testMain.c $(SRC)linkList.c $(SRC)patient.c $(SRC)queues.c $(SRC)dummy.c -o $(BIN)runTest

runMe:
	$(BIN)runMe 

runTest:
	$(BIN)runTest

clean:
	rm $(BIN)runMe