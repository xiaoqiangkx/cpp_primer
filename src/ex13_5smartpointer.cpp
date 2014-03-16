#include <iostream>
using namespace std;

class U_Ptr{
   friend class hasPtr;
   int *ip;
   size_t use;
   U_Ptr(int *p): ip(p), use(1) {};
   ~U_Ptr() { delete ip; }
};

class hasPtr{
    public:
       hasPtr(int *p, int i): ptr(new U_Ptr(p)), val(i) {}

       hasPtr(const hasPtr &orig): val(orig.val), ptr(orig.ptr) { ptr->use++; }
       hasPtr& operator=(const hasPtr&);
       ~hasPtr();

       int *get_ptr() const {return ptr->ip; }
       void set_ptr(int *p) { ptr->ip = p;}

       int get_val() const { return val; }
       void set_val(int i) { val = i;}

       int get_ptr_val() const { return *(ptr->ip); };
       void set_ptr_val(int i) { *(ptr->ip) = i;}
    private:
        U_Ptr *ptr;
        int val;
};


hasPtr& hasPtr::operator=(const hasPtr& orig) {
    ++orig.ptr->use;
    if (--ptr->use == 0) delete ptr;   //delete the latter one.
    ptr = orig.ptr;
    val = orig.val;
    return *this;
}
hasPtr::~hasPtr() {
    if (--ptr->use == 0) delete ptr;
}

int main(int argc, char* argv[]) {
    int *p = new int(20);
    hasPtr h1(p, 1);
    hasPtr h2(h1);
    hasPtr h3 = h1;
    return 0;
}
