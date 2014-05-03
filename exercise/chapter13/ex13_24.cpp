#include <iostream>
using namespace std;

class U_ptr {
    friend class HasPtr;
    int* ptr;
    size_t use;
    U_ptr(int *p): ptr(p), use(1) {}
    ~U_ptr() { if(ptr) delete ptr; }
};

class HasPtr {
    public:
        HasPtr(int *p): ptr(new U_ptr(p)) {};
        ~HasPtr() { if (--ptr->use == 0) delete ptr; }
        HasPtr(const HasPtr& orig): ptr(orig.ptr) { ++orig.ptr->use; }
        HasPtr& operator=(const HasPtr& orig) {
            ++orig.ptr->use;
            if (--ptr->use == 0)
                delete ptr;

            ptr = orig.ptr;
            return *this;
        }
    private:
       U_ptr *ptr; 
};

int main() {
    int *a = new int(1);
    HasPtr h1(a);
    HasPtr h2 = h1;
    h2 = h1;

    return 0;
}
