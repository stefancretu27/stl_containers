CFLAGS = -std=c++11 -Wall -g
CC = g++

all:
	$(CC) $(CFLAGS) main.cpp array_operations.cpp -o containers.bin
	
clean:
	rm *.exe; rm *.o; rm *.bin