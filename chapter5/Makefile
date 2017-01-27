CC=g++
FLAGS= 

all: pre-build main-build post-build

pre-build:
	mkdir -p output

main-build: output/Random output/BiasedRandom

output/Random: Random.cpp
	$(CC) $(FLAGS) -o $@ $^

output/BiasedRandom: BiasedRandom.cpp
	$(CC) $(FLAGS) -o $@ $^

post-build:

clean:
	rm -rf output

debug: FLAGS += -g
debug: all

