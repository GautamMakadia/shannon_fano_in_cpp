run: output
	./output

build: main.o
	g++ main.o -o output && rm -rf main.o

main.o: main.cpp
	g++ -c main.cpp

clear: 
	rm -rf output *.o