all:
	g++ -std=c++2a examples.cpp -o run
test:
	g++ -std=c++2a testBench.cpp -o test

clean:
	rm run test
