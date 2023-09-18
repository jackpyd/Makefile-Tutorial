# 使用伪目标
.PHNOY:clean

TARGET = calc
# OBJ = add.o sub.o calc.o
# 将.cpp 文件替换为 .o文件
OBJ = $(patsubst %.cpp,%.o,$(wildcard *.cpp))


$(TARGET):$(OBJ)
	gcc $(OBJ) -o $(TARGET)
	
%.o:%.cpp
	gcc -c $^ -o $@

clean:
	rm -rf *.o  $(TARGET)

