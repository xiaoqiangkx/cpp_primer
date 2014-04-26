#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Handler {
    public:
        Handler(T *_ptr = NULL): ptr(_ptr), use(new size_t(1)) {}   /*size_t is user_defined class but typedef for int */
        Handler(const Handler& h): ptr(h.ptr), use(h.use) { ++(*use);}
        Handler& operator=(const Handler& rhs) {    /* right hand side */
            ++*(rhs.use);
            rem_ref();
            use = rhs.use;
            ptr = rhs.ptr;
            return *this;
        }

        ~Handler() {
            rem_ref();
        }

        T& operator*() {
            if (ptr != NULL)    return *ptr;
            throw new runtime_error("dereference of unbound handler");
        }

        const T& operator*() const{
            if (ptr != NULL)    return *ptr;
            throw new runtime_error("dereference of unbound handler");
        }

        T* operator->() {
            if (ptr != NULL)    return ptr;
            throw new runtime_error("access through unbound handler");
        }

        const T* operator->() const{
            if (ptr != NULL)    return ptr;
            throw new runtime_error("access through unbound handler");
        }

    private:
        T *ptr; /* every handler use the same ptr and use */
        size_t *use;
        void rem_ref() {
            if (0 == --*use) {
                delete use; 
                delete ptr;
                cout << "delete data" << endl;
            } else {
                cout << "count --: " << *use << endl;
            }
        }
};

int main() {
    int *data = new int(12);
    Handler<int> hp(data);
    Handler<int> hp2(hp);
    const Handler<int> hp3(hp);
    cout << *hp << endl;
    cout << *hp2 << endl;
//    cout << (hp3->) << endl;
    return 0;
}
