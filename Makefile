CFLAGS = -std=c++11 -Wall -g
CC = g++
SOURCES = array_operations.cpp vector_operations.cpp deque_operations.cpp forward_list_operations.cpp

all:
	$(CC) $(CFLAGS) main.cpp $(SOURCES) -o containers.bin
	
clean:
	rm *.bin
