SOURCE = $(wildcard ./*.cpp ./*.c)  # 当前目录下的 .cpp和.c文件
OBJ = $(patsubst %.cpp, %.o, $(SOURCE)) # 将.cpp 替换为 .o
OBJ := $(patsubst %.c, %.o, $(OBJ))    # 将.c 替换为 .o

.PHONY:clean

$(TARGET):$(OBJ)
	$(CXX) $^ -o $@

clean:
	$(RM) $(TARGET) $(OBJ)
