# Makefile 中通用部分做公共文件头

Makefile 中，都是先展开所有变量，再调用指令

- `=` 赋值，但是用终值，就是不管变量调用写在赋值前还是赋值后，调用时都是取终值。（可能会出现循环引用的问题）
- `:=` 也是赋值，但是只受当前行及之前的代码影响，而不会受后面的赋值影响

## 案例

项目目录结构如下：

```shell
.
├── Makefile
├── v1
│   ├── Makefile
│   ├── a.cpp
│   ├── b.cpp
│   ├── c.cpp
│   └── cpp
└── v2
    ├── Makefile
    ├── x.c
    ├── x.o
    ├── y.c
    ├── y.o
    ├── z
    ├── z.c
    └── z.o
```

通用的 Makefile 部分：

```Makefile
SOURCE = $(wildcard ./*.cpp ./*.C)  # 当前目录下的 .cpp和.c文件
OBJ = $(patsubst %.cpp, %.o, $(SOURCE)) # 将.cpp 替换为 .o
OBJ := $(patsubst %.c, %.o, $(OBJ))    # 将.c 替换为 .o

.PHONY:clean

$(TARGET):$(OBJ)
	$(CXX) $^ -o $@

clean:
	$(RM) $(TARGET) $(OBJ)
```

### v1

a.cpp:

```cpp
#include <iostream>

void func_a(){
	printf("func-a.cpp");
}
```

b.cpp:

```cpp
#include <iostream>

void func_b(){
	printf("func-b.cpp");
}
```

c.cpp:

```cpp
extern void func_a();
extern void func_b();

int main(){
	func_a();
    func_b();

    return 0;
}

```

Makefile:

```Makefile
TARGET = c

include ../Makefile
```

### v2

x.c:

```c
#include <stdio.h>

void func_x(){
	printf("func-x.c");
}
```

y.c:

```c
#include <stdio.h>

void func_x(){
	printf("func-y.c");
}
```

z.c:

```c
extern void func_x();
extern void func_y();

int main(){
	func_x();
    func_y();
    return 0;
}
```

Makefile:

```Makefile
TARGET = z

include ../Makefile
```
