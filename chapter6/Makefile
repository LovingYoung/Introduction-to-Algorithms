CC=g++
FLAGS=

all: pre-build main-build post-build

pre-build:
	mkdir -p output

main-build: output/Heapsort

output/Heapsort: Main.cpp Heap.h
	$(CC) $(FLAGS) -o $@ $<

post-build:

debug: FLAGS += -g
debug: all

clean:
	rm -rf output
