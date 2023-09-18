# Makefile 变量

## 系统变量

- `$*`: 不包括扩展名的目标文件名称
- `$+`: 所有的依赖文件，以空格分隔
- `$<`: 表示规则中的第一个条件
- `$?`: 所有时间戳比目标文件晚的依赖文件，以空格分隔
- `$@`: 目标文件的完整名称
- `$^`: 所有不重复的依赖文件，以空格分隔
- `$%`: 如果目标是归档成员，则该变量表示目标的归档成员名称

使用系统变量优化 Makefile：

```Makefile
# 使用$^ $@ 优化
calc:add.o sub.o calc.o
	gcc $^ -o calc

calc.o:calc.cpp
	gcc -c $^ -o $@

add.o:add.cpp
	gcc -c $^ -o $@

sub.o:sub.cpp
	gcc -c $^ -o $@

clean:
	rm -rf *.o calc
```

## 系统常量（可用 make -p 查看）

- `AS`: 汇编程序的名称，默认为 as
- `CC`: C 编译器名称，默认为 cc
- `CPP`: C 预编译器名称，默认为 cc -E
- `CXX`: C++编译器名称，默认为 g++ （可以实现跨平台）
- `RM`: 文件删除程序别名，默认 rm -f

使用系统常量优化 Makefile：

```Makefile
# 使用系统常量优化
# CXX： C++编译器
# RM: 删除程序的别名，默认 rm -f
calc:add.o sub.o calc.o
	$(CXX) $^ -o calc

calc.o:calc.cpp
	$(CXX) -c $^ -o $@

add.o:add.cpp
	$(CXX) -c $^ -o $@

sub.o:sub.cpp
	$(CXX) -c $^ -o $@

clean:
	$(RM) -rf *.o calc
```

## 自定义变量

```Makefile
定义：变量名=变量值
使用：$(变量名)/${变量名}
```

使用自定义变量优化 Makefile：

```Makefile
# 使用自定义变量优化

TARGET = calc
OBJ = add.o sub.o calc.o

calc:$(OBJ)
	$(CXX) $^ -o $(TARGET)

calc.o:calc.cpp
	$(CXX) -c $^ -o $@

add.o:add.cpp
	$(CXX) -c $^ -o $@

sub.o:sub.cpp
	$(CXX) -c $^ -o $@

clean:
	$(RM) -rf *.o $(TARGET)
```
