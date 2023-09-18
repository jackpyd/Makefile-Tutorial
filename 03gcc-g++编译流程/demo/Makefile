# 全部编译
cal:
	gcc add.cpp sub.cpp calc.cpp -o calc

# 二次编译时，保证只有改动的文件才进行二次编译
calc2:add.o sub.o
	gcc add.o sub.o  calc.cpp -o calc
	
add.o:add.cpp
	gcc -c add.cpp -o add.o

sub.o:sub.cpp
	gcc -c sub.cpp -o sub.o

clean:
	rm -rf *.o calc

