# make install

## 命令及作用

1. make

- 将源文件编译成二进制可执行文件（包括各种库文件）

2. make install

- 创建目录，将可执行文件拷贝到指定目录（安装目录）
- 加全局可执行的路径
- 加全局的启动暂停脚本

3. make clean

- 重置编辑环境，删除无关文件

## 示例

`main.cpp`:

```cpp
#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
    int i = 0;
    while (true){
        cout<<"main-running-"<<i++<<endl;
        sleep(1);
    }

    return 0;
}
```

`Makefile`:

```Makefile

TARGET:=main
OBJ:=$(TARGET).o

PATHS:=/tmp/test-main/ # 安装目录
BIN:=/usr/local/bin/  # 全局可执行文件路径


START_SH:=$(TARGET)_start
STOP_SH:=$(TARGET)_stop
LOG:=$(PATHS)$(TARGET).log


$(TARGET):$(OBJ)
	$(CXX) $^ -o $@


install:$(TARGET)
	if [ -d $(PATHS) ];\
		then echo $(PATHS) exist; \
	else \
	  	mkdir $(PATHS);\
	  	cp $(TARGET) $(PATHS);\
  		ln -sv $(PATHS)$(TARGET) $(BIN);\
  		touch $(LOG);\
  		chmod a+rwx $(LOG);\
  		echo "$(TARGET)>$(LOG) & echo $(TARGET) running...">$(PATHS)$(START_SH);\
  		echo "killall $(TARGET)">$(PATHS)$(STOP_SH);\
  		chmod a+x $(PATHS)$(START_SH);\
  		chmod a+x $(PATHS)$(STOP_SH);\
  		ln -sv $(PATHS)$(START_SH) $(BIN);\
  		ln -sv $(PATHS)$(STOP_SH) $(BIN);\
  	fi;

clean:
	$(RM) $(TARGET) $(OBJ) $(BIN)$(TARGET) $(BIN)$(START_SH) $(BIN)$(STOP_SH)
	$(RM) -rf $(PATHS)

.PHONY:clean install
```

使用：

```shell
make && make install
```

核心逻辑：

- 判断安装目录是否存在，不存在则创建目录
- 把可执行文件拷贝到安装目录
- 创建启停脚本，并并增加权限，创建一个同步的软链接
- 创建日志文件，并增加权限，创建一个同步的软链接
