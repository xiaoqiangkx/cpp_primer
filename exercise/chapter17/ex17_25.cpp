#include <iostream>
using namespace std;

class X {};
class A {};
class B: public A {};
class C: private B {};
class D: public X, public C {};

int main() {
    D *pd = new D();
    /* pa,pb is inaccessable to the base of pd */
   //  A *pa = pd;
   //  B *pb = pd;
    C *pc = pd;
    X *px = pd;
    delete pd;
    return 0;
}
