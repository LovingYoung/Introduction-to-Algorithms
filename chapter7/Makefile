CC=g++
FLAGS=

all: pre-build main-build post-build

pre-build:
	mkdir -p output

main-build: output/Quicksort

output/Quicksort: main.cpp QuickSort.h
	$(CC) $(FLAGS) -o $@ $<

post-build:

debug: FLAGS += -g
debug: all

clean:
	rm -rf output
