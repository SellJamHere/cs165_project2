## makefile for Project 2
##
a.out		:		main.o BigInt.o
							g++ main.o BigInt.o
							@echo "Linking files together..."

main.o				:		main.cpp BigInt.cpp
							g++ -c main.cpp
							@echo "Compiling main.cpp ..."

BigInt				:		BigInt.cpp
							g++ -c BigInt.cpp
							@echo "Compiling BigInt.cpp ..."

clean				:	
							@echo "cleaning up after make, removing object files..."
							rm -f *.o a.out
							@echo "done"
