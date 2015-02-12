lab2: lab2.o list.o table.o
	g++ -g -std=c++11 lab2.o list.o table.o -o lab2

lab2.o: lab2.cpp list.o table.o
	g++ -c -g -std=c++11 lab2.cpp

list.o: list.cpp 
	g++ -c -g -std=c++11 list.cpp

table.o: table.cpp
	g++ -c -g -std=c++11 table.cpp

clean:
	rm -f *~ *.o
