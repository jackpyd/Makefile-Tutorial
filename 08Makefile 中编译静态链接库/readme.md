# Makefile 中编译静态链接库

## 静态链接库

静态链接库：

- 会把库中的代码编译到二进制文件中，当程序编译完成后，该库文件可以删除
- Windows 中后缀为 .lib
- Linux 中后缀为 .a
- 优点：
  - 运行时不需要动态加载库，速度快
- 缺点：
  - 程序体积更大，并且库中的内容如果有更新，则需要重新编译生成程序

## 案例

项目结构：

```
.
├── Makefile
├── aTest.h
├── main
├── main.cpp
├── main.txt
├── soTest.h
├── v1
│   ├── Makefile
│   ├── libsoTest.so
│   ├── soTest.cpp
│   ├── soTest.h
│   ├── test
│   └── test.cpp
└── v2
    ├── Makefile
    ├── aTest.cpp
    ├── aTest.h
    ├── aTest.o
    └── libaTest.a
```

### 项目发布前

`aTest.h`:

```cpp
class aTest{
public:
    void func1();
};
```

`aTest.cpp`:

```cpp
#include <iostream>
#include "aTest.h"

void aTest::func1(){
    printf("aTest-func1\n");
}
```

编译静态库文件`libaTest.a`：

```shell
g++ -c aTest.cpp -o aTest.o
ar -r libaTest.a aTest.o
```

### 项目发布

`aTest.h`:

```cpp
class aTest{
public:
    void func1();
};
```

`main.cpp`:

```cpp
#include <iostream>
#include "soTest.h"
#include "aTest.h"

class MainTest:public soTest{
public:
    void func2(){
        printf("MainTest-func2\n");
    }
    void func3(){
        printf("MainTest-func3\n");
    }
};

int main(){
    MainTest t1;
    t1.func1();
    t1.func2();
    t1.func3();

    printf("\n\n");

    aTest t2;
    t2.func1();

    return 0;
}
```

指定动态库文件 soTest 和静态库文件 aTest，编译后由 main.cpp 文件产生 main.o 文件:

```shell
g++ -lsoTest -L./v1  -laTest -L./v2  main.cpp -o main
```

生成一个类似于反汇编的文本文档，进入搜索可以找到 aTest::func1() 的定义，但只能找到 soTest::func1()、soTest::func2()、soTest::func3() 的引用:

```shell
objdump -DC main>main.txt
```

### Makefile

`002/Makefile`:

```Makefile
libaTest:
	$(CXX) -c aTest.cpp -o aTest.o
	$(AR) -r libaTest.a aTest.o

clean:
	$(RM) *.o *.a
```

```Makefile
TARGET = main
LDFLAGS = -L./v1 -L./v2
LIBS = -lsoTest -laTest

$(TARGET):
	$(CXX) $(LIBS) $(LDFLAGS) main.cpp -o $(TARGET)

clean:
	$(RM) $(TARGET)
```
