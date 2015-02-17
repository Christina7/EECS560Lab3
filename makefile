lab3: lab3.o table.o
	g++ -g -std=c++11 lab3.o table.o -o lab3

lab3.o: lab3.cpp table.o
	g++ -c -g -std=c++11 lab3.cpp

table.o: table.cpp
	g++ -c -g -std=c++11 table.cpp

clean:
	rm -f *~ *.o
