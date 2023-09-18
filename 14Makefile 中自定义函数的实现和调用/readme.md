# Makefile 中自定义函数的实现和调用

## 自定义函数

- 自定义函数不是真正的函数，本质上是多行命令放在了目标外。
- 可以传递参数：
  - $(0) 为本身文件名
  - ( 1 ) ∗ ∗ 为要接受的参数 ∗ ∗ (1)** 为要接受的参数 **(1)∗∗ 为要接受的参数 ∗∗(A)
  - $(2) 为要接受的参数 asd
- 没有返回值
  - 加 echo 命令，将 return 当作一个字符串，和 123 一起输出

## 示例

```Makefile
A := 123

define FUNC1
	@echo -------func1-------
	echo arg: $(0) $(1) $(2)
	@echo -------------------
endef

define FUNC2
	@echo -------func2-------
	echo return 123
	@echo -------------------
endef

define FUNC3
	@echo -------func3-------
	echo $(shell ls)
	@echo -------------------
endef

all:
	$(call FUNC1, $(A), asd)
	$(call FUNC2)
	$(call FUNC3)
```

输出：

```shell
-------func1-------
echo arg: FUNC1  123  asd
arg: FUNC1 123 asd
-------------------
-------func2-------
echo return 123
return 123
-------------------
-------func3-------
echo Makefile
Makefile
-------------------
```
