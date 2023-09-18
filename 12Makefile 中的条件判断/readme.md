# Makefile 中的条件判断

## 条件判断语句

- `ifeq`：判断是否相等，相等返回 true，不相等返回 false (if equal)
- `ifneq`：判断是否不相等，不相等返回 true，相等返回 false (if not equal)
- `ifdef`：判断变量是否存在，存在返回 true，不存在返回 false (if defined)
- `ifndef`：判断变量是否不存在，不存在返回 true，存在返回 false （if not defined）

注意事项：

- ifeq、ifneq、ifdef、ifndef 与条件之间要有空格，不然会报错
- 可以只有 if，没有 else
- 没有 elseif 的用法，如果要实现 elseif，就要写嵌套

命令行传参：

- `make -f Makefile FLAG=456`

## 示例

```Makefile
A := 123

RS1 :=
RS2 :=
RS3 :=
RS4 :=

ifeq ($(A), 123)
	RS1 := RS1-yes
else
	RS1 := RS1-no
endif

ifneq ($(A), 123)
	RS2 := RS2-yes
else
	RS2 := RS2-no
endif

ifdef A
	RS3 := RS3-yes
else
	RS3 := RS3-no
endif

ifndef A
	RS4 := RS4-yes
else
	RS4 := RS4-no
endif

ifdef FLAG
	FLAG := default
endif

all:
	echo $(RS1)
	echo $(RS2)
	echo $(RS3)
	echo $(RS4)
	echo flag = $(FLAG)
```
