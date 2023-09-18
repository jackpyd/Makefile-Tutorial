# Makefile 中的伪目标和模式匹配

## 伪目标

声明目标为伪目标之后，makefile 将不会判断目标是否存在或该目标是否需要更新

```Makefile
.PHONY:目标
```

比如文件夹下有`clean`文件，则`make clean`命令无法执行，因为会将`clean`识别为目标文件，而非命令参数，为了避免这种情况，就需要用到伪目标：

```Makefile
# 使用伪目标
.PHNOY:clean

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
```

## 模式匹配

目标和依赖相同部分，可以用%来通配：

```Makefile
%目标:%依赖
```

比如`add.o sub.o calc.o`，可以通过`%.o:%.cpp`产生：

```Makefile
# 使用伪目标
.PHNOY:clean

TARGET = calc
OBJ = add.o sub.o calc.o


$(TARGET):$(OBJ)
	gcc $(OBJ) -o $(TARGET)

%.o:%.cpp
	gcc -c $^ -o $@

clean:
	rm -rf *.o  $(TARGET)
```

## 内置函数

获取对应文件路径下的对应模式的文件名:

```Makefile
$(wildcard 文件列表)
$(wildcard ./*.cpp) # 获取当前目录下所有的.cpp文件名
```

将文件列表中想要改变的源模式替换成想要的目标模式:

```Makefile
$(patsubst 源模式, 目标模式, 文件列表)
$(patsubst %.cpp, %.o, $(wildcard ./*.cpp)) # 将对应的.cpp文件替换为**.o**文件
```

使用内置函数优化 Makefile 文件：

```Makefile
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
```
