output: main.o message.o
	g++ -std=c++11 main.o message.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp
	
message.o: message.cpp message.h
	g++ -std=c++11 -c message.cpp

clean:
	rm *.o output 