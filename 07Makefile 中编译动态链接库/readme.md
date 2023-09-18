# Makefile 中编译动态链接库

## 动态链接库

动态链接库：

- 不会把代码编译到二进制文件中，而是在运行时才去加载，所以需要维护一个地址
- 动态：动态加载，运行时才加载
- 链接：指库文件和二进制程序分离，用某种手段维护两者之间的关系
- 库：库文件
  - Windows 中后缀为 .dll
  - Linux 中后缀为 .so
- 优点：
  - 动态链接库可以被多个程序使用，避免重复加载

链接命令的常用选项：

- -fPIC: 产生位置无关的代码
- -shared: 共享
- -l: 指定动态库
- -I: 指定头文件目录，默认当前目录
- -L 手动指定库文件搜索目录，默认只链接共享目录

## 演示

目录结构：

```shell
.
├── main.cpp
├── soTest.h
└── v1
    ├── Makefile
    ├── libSoTest.so
    ├── soTest.cpp
    ├── soTest.h
    └── test.cpp
```

动态链接库文件`soTest.h`:

```cpp
class soTest{
public:
    void func1();
    virtual void func2();
    virtual void func3() = 0;
};
```

动态链接库文件`soTest.cpp`:

```cpp
#include <iostream>
#include "soTest.h"

void soTest::func1(){
    printf("func1\n");
}

void soTest::func2(){
    printf("func2\n");
}
```

生成动态链接库文件：

```shell
g++ -shared -fPIC soTest.cpp -o libSoTest.so
```

> soTest.cpp 编译后会产生 libsoTest.so，不用担心文件名不同会出现问题，在后续引用中，lib 自动会被丢弃

测试文件`test.cpp`：

```cpp
#include <iostream>
#include "soTest.h"

class Test:public soTest{
public:
    void func2(){
        printf("Test-func2\n");
    }
    void func3(){
        printf("Test-func3\n");
    }
};

int main(){
    Test t1;
    t1.func1();
    t1.func2();
    t1.func3();

    return 0;
}
```

指定动态库文件 soTest，编译后由 Test.cpp 文件产生 Test.o 文件：

```shell
g++ -lsoTest -L./ test.cpp -o test
```

假设项目发布文件由`main.cpp`编译产生：

```cpp

```

编译：

```shell
g++ -lsoTest -L./v1 main.cpp -o main
```

编译报错，无法找到 **.so** 文件：

```shell
❯ g++ -lsoTest -L./v1  main.cpp -o main
❯ ./main
dyld[46441]: Library not loaded: 'libSoTest.so'
  Referenced from: '/Users/jackc/Desktop/study/Study-Makefile/07Makefile 中编译动态链接库/demo/main'
  Reason: tried: 'libSoTest.so' (no such file), '/usr/local/lib/libSoTest.so' (no such file), '/usr/lib/libSoTest.so' (no such file), '/Users/jackc/Desktop/study/Study-Makefile/07Makefile 中编译动态链接库/demo/libSoTest.so' (no such file), '/usr/local/lib/libSoTest.so' (no such file), '/usr/lib/libSoTest.so' (no such file)
[1]    46441 abort      ./main
```

解决办法：

1. 将动态库文件移动到 main.cpp 文件同级目录下
2. 运行时手动指定动态库文件所在目录:
   - `LD_LIBRARY_PATH = ./v1`
   - `export LD_LIBRARY_PATH`
3. 将动态库文件复制到动态链接库默认路径下（不推荐复制，污染原库环境）
   - `cp libsoTest.so /usr/local/lib`

> Linux 默认动态库路径配置文件:
> /etc/ld.so.conf
> /etc/ld.so.conf.d/\*.conf

### 编写 Makefile 文件

`v1/Makefile`:

```Makefile

Test:libsoTest.so
	$(CXX) -lsoTest -L./ test.cpp -o test
	cp libsoTest.so /usr/local/lib  # 路径最好为main.cpp同级目录
libsoTest.so:
	$(CXX) -shared -fPIC soTest.cpp -o libsoTest.so

clean:
	$(RM) *.so Test
	$(RM) /usr/local/lib/libsoTest.so
```

## 虚函数与纯虚函数

虚函数和纯虚函数的区别：

- 虚函数：在派生类中重新定义，基类指针或引用可以指向派生类对象
- 纯虚函数：在基类中定义，派生类中需要重新定义
- 主要区别：
  - 虚函数可以有实现，纯虚函数不能有实现
  - 虚函数可以被重载，纯虚函数不可以被重载
  - 虚函数可以被继承，纯虚函数不可以被继承
  - 虚函数可以被 virtual 修饰，纯虚函数不可以被 virtual 修饰
