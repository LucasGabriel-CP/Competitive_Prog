EXE = marat
CC = g++
CFLAGS = -fno-omit-frame-pointer -Wshadow -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts -std=c++20 -Wall -Wextra -g -DPIZZA

main:
	$(CC) $(CFLAGS) -o $(EXE) marat.cpp && marat.exe

in:
	$(CC) $(CFLAGS) -o $(EXE) marat.cpp && marat.exe < input.txt