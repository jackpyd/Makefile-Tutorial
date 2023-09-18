calc:add.o sub.o calc.o
	gcc add.o sub.o  calc.o -o calc
	
calc.o:calc.cpp
	gcc -c calc.cpp -o calc.o

add.o:add.cpp
	gcc -c add.cpp -o add.o

sub.o:sub.cpp
	gcc -c sub.cpp -o sub.o

clean:
	rm -rf *.o calc

