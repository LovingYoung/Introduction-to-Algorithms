FLAGS = 

all: pre-build main-build

debug: FLAGS += -g
debug: all

pre-build:
	mkdir -p output;

main-build: output/MatricesMultiplication

output/MatricesMultiplication: C_4_2.cpp
	g++ $(FLAGS) -o $@ $^

clean: 
	rm -rf output
