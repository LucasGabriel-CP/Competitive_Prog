filename = main

ifeq ($(OS), Windows_NT)
	EXE = $(filename).exe
else
	EXE = ./$(filename)
endif

CC = g++
CFLAGS = -fno-omit-frame-pointer -Wshadow -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts -std=c++20 -Wall -Wextra -g -DPIZZA

main:
	$(CC) $(CFLAGS) -o $(EXE) $(filename).cpp && $(EXE)

in:
	$(CC) $(CFLAGS) -o $(EXE) $(filename).cpp && $(EXE) < input.txt
