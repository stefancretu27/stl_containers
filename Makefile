CFLAGS = -std=c++11 -Wall -g
CC = g++
SEQ_CONTAINERS_SOURCES = array_operations.cpp vector_operations.cpp deque_operations.cpp forward_list_operations.cpp list_operations.cpp
ASSOC_CONTAINERS_SOURCES = set_operations.cpp

all:
	$(CC) $(CFLAGS) main.cpp $(SEQ_CONTAINERS_SOURCES) $(ASSOC_CONTAINERS_SOURCES) -o containers.bin
	
clean:
	rm *.bin
