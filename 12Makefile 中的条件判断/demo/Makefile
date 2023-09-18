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

# 没有 elseif 的用法，如果要实现 elseif，就要写嵌套
ifeq ($(A), 321)
	RS1 := 321
else
	ifeq ($(A), 123)
        RS1 := 123
    else
        RS1 := 0
    endif
endif

all:
	echo $(RS1)
	echo $(RS2)
	echo $(RS3)
	echo $(RS4)
	echo flag = $(FLAG)
