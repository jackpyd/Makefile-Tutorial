TARGET = main
LDFLAGS = -L./v1 -L./v2
LIBS = -lsoTest -laTest

$(TARGET):
	$(CXX) $(LIBS) $(LDFLAGS) main.cpp -o $(TARGET)
	
clean:
	$(RM) $(TARGET)
