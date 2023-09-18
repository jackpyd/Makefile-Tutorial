
Test:libsoTest.so
	$(CXX) -lsoTest -L./ test.cpp -o test
	cp libsoTest.so /usr/local/lib  # 路径最好为main.cpp同级目录
libsoTest.so:
	$(CXX) -shared -fPIC soTest.cpp -o libsoTest.so

clean:
	$(RM) *.so Test
	$(RM) /usr/local/lib/libsoTest.so