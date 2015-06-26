exe: main.cpp stack.o
	g++ main.cpp stack.o -lncurses -o exe
stack.o: stack.hpp stack.cpp
	g++ -c stack.cpp
rm:
	rm *.o