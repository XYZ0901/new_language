#include <iostream>
#include <memory>

#include <Lexer.h>

using namespace std;

class A {
private:
    int val;
public:
   virtual ~A() {
        cout<<"A destroy!"<<endl;
    }
};

class B: public  A {
private:
    int *arr;
public:
    B() {
        arr = new int[10];
    }
    ~B() {
        cout<<"B destroy!"<<endl;
        delete arr;
    }
};

int main() {
    A *base = new B();
    delete base;
    return 0;
}