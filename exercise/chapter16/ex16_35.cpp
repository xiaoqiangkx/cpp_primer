#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class CheckedPtr {
    public:
        CheckedPtr(T* _beg, T* _end): beg(_beg), end(_end), cur(_beg) {} 

        CheckedPtr& operator++() {
           if (cur == end) {
               throw out_of_range("invalid current pointer");
           }
           cur++;
           return *this; 
        }


        CheckedPtr& operator--() {
           if (cur == beg) {
               throw out_of_range("invalid current pointer");
           }
           cur--;
           return *this; 
        }

        
        CheckedPtr operator--(int) {
           CheckedPtr<T> ret(*this);
           --(*this);
           return ret; 
        }

        CheckedPtr operator++(int) {
           CheckedPtr<T> ret(*this);
           ++(*this);
           return ret; 
        }

        T& operator[](const size_t index) {
           if (cur + index >= end) {
               throw out_of_range("invalid current pointer");
           }
            return *(cur + index);
        }
        
        const T& operator[](const size_t index) const{
           if (cur + index >= end) {
               throw out_of_range("invalid current pointer");
           }
           return *(cur + index);
        }

        T& operator*() {
            return *cur;
        }


        const T& operator*() const {
            return *cur;
        }
    private:
        T* beg;
        T* end;
        T* cur;

};

int main() {
    int a[] = {1, 4, 5, 3, 1};
    CheckedPtr<int> cPtr(a, a+5);
    cout << *(++cPtr) << endl;
    cout << *(--cPtr) << endl;
    cout << *(cPtr++) << endl;
    cout << *(cPtr--) << endl;

    cout << cPtr[2] << endl;
    cout << *cPtr << endl;
    return 0;
}
