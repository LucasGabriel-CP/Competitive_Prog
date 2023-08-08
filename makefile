EXE = marat
CC = g++
CFLAGS = -std=c++20 -Wall -Wextra -g -DPIZZA

main: marat.o
	$(CC) $(CFLAGS) -o $(EXE) marat.o && marat.exe

in: marat.o
	$(CC) $(CFLAGS) -o $(EXE) marat.o && marat.exe < input.txt

marat.o: marat.cpp
	$(CC) $(CFLAGS) -c marat.cpp