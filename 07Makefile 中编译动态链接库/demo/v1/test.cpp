#include <iostream>
#include "soTest.h"

class Test:public soTest{
public:
    void func2(){
        printf("Test-func2\n");
    }
    void func3(){
        printf("Test-func3\n");
    }
};

int main(){
    Test t1;
    t1.func1();
    t1.func2();
    t1.func3();

    return 0;
}