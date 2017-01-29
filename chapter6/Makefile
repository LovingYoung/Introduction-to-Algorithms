CC=g++
FLAGS=

all: pre-build main-build post-build

pre-build:
	mkdir -p output

main-build: output/Heapsort output/PriorityQueue

output/Heapsort: main.cpp Heap.h
	$(CC) $(FLAGS) -o $@ $<

output/PriorityQueue: PriorityQueue.cpp PriorityQueue.h Heap.h
	$(CC) $(FLAGS) -o $@ $<

post-build:

debug: FLAGS += -g
debug: all

clean:
	rm -rf output
