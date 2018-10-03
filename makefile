CC=gcc
CFLAGS=-I.

test_hw2: hw2_P52.o P52SSE.o main.o
	     $(CC) -o test_hw2 P52SSE.o hw2_mult.o main.o
