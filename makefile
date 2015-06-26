exe: main.cpp Stack.o
	g++ main.cpp Stack.o -lncurses -o exe
Stack.o: Stack.hpp Stack.cpp
	g++ -c Stack.cpp
rm:
	rm *.o