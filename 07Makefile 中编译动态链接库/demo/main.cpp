#include <iostream>
#include "soTest.h"

class MainTest:public soTest{
public:
    void func2(){
        printf("MainTest-func2\n");
    }
    void func3(){
        printf("MainTest-func3\n");
    }
};

int main(){
    MainTest t1;
    t1.func1();
    t1.func2();
    t1.func3();
    
    return 0;
}
