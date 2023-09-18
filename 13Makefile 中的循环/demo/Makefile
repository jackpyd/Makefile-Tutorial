TARGET = a b c d

all:
	touch $(TARGET)
	touch $(foreach v, $(TARGET), $v)
	touch $(foreach v, $(TARGET), $v.txt)
	
clean:
	$(RM) $(TARGET) *.txt
