# Makefile 中调用 shell 命令

Makefile 调用 shell 命令的格式：

```Makefile
$(shell 命令)
```

## 示例

```Makefile
FILE = abc

A := $(shell ls ../)
B := $(shell pwd)
C := $(shell if [ ! -f $(FILE) ]; then touch $(FILE); fi;)

a:
	echo $(A)
	echo $(B)
	echo $(C)

clean:
	$(RM) $(FILE)
```

- `$(shell ls ../)` 列出上级目录中的所有目录
- `$(shell pwd)` 显示当前所在工作目录的绝对路径
- `$(shell if [ ! -f $(FILE) ]; then touch $(FILE); fi;)` 判断文件是否存在
