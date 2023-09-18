#include <iostream>
#include "soTest.h"
#include "aTest.h"

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
    
    printf("\n\n");
    
    aTest t2;
    t2.func1();
    
    return 0;
}
