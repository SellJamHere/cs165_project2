## makefile for Project 2
##
a.out		:		main.o cTimer.o BigInt.o Random.o 
					g++ main.o cTimer.o BigInt.o Random.o
					@echo "Linking files together..."

main.o		:		main.cpp cTimer.c BigInt.cpp Random.cpp
					g++ -c main.cpp
					@echo "Compiling main.cpp ..."

cTimer		:		cTimer.c
					gcc -c cTimer.c
					@echo "Compiling cTimer.c ..."

BigInt		:		BigInt.cpp
					g++ -c BigInt.cpp
					@echo "Compiling BigInt.cpp ..."

Random		:		Random.cpp
					g++ -c Random.cpp
					@echo "compiling Random.cpp ..."

clean		:	
					@echo "cleaning up after make, removing object files..."
					rm -f *.o a.out
					@echo "done"
