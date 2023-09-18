# Makefile 中的嵌套调用和多项目同时编译

## 示例

项目目录结构：

```shell
.
├── Makefile
├── Makefile-head
├── v1
│   ├── Makefile
│   ├── a.cpp
│   ├── b.cpp
│   ├── c.cpp
│   └── cpp
└── v2
    ├── Makefile
    ├── x.c
    ├── y.c
    └── z.c
```

其中：

- `Makefile-head`是`v1`和`v2`的公共部分

下面的`Makefile`实现了同时编译`v1`和`v2`和同时执行其中的`make clean`命令:

```Makefile
.PHONY:v1 v2

DIR = v1 v2

all:$(DIR)

$(DIR):
	make -C $@

clean:
	echo $(shell for dir in $(DIR); do make -C $$dir clean; done)
```

- `make -C $@ `：实现了多项目同时编译
