# Makefile 中的循环

## 循环

makefile 中只有一个循环 foreach，只支持 GNU Make，其他平台的 make 需要使用 shell 中的循环来实现。
foreach 可以在循环中逐个的修改值

Makefile：

```Makefile
TARGET = a b c d

all:
	touch $(TARGET)
	touch $(foreach v, $(TARGET), $v)
	touch $(foreach v, $(TARGET), $v.txt)

clean:
	$(RM) $(TARGET) *.txt
```
