#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <memory>
using namespace std;

/**
 * 实现push_back, pop_back等方法
 */
template <typename T> 
class Vector {
    public:
        Vector(): elements(NULL), first_free(NULL), end(NULL) {}

        bool empty() const {
            return elements == first_free;
        }

        size_t size() const {
            return first_free - elements;
        }

        size_t capacity() const {
            return end - elements;
        }

        bool full() const {
            return end == first_free;
        }
        void push_back(const T& t);
        void pop_back();


    private:
        static allocator<T> alloc;
        T* elements;
        T* first_free;
        T* end;

        void reallocate();
};

template <typename T> allocator<T> Vector<T>::alloc;

template <typename T>
void Vector<T>::push_back(const T& t) {
    if (full())
        reallocate();

    alloc.construct(first_free, t);
    first_free++; 
}

template <typename T>
void Vector<T>::pop_back() {
   if (empty()) {
       throw underflow_error("pop_back from empty vector");
   }

   alloc.destroy(--first_free);
}

template <typename T>
void Vector<T>::reallocate() {
    size_t size = Vector<T>::size();
    size_t newCapacity = 2* max(size_t(1), size);

    T* newElements = alloc.allocate(newCapacity);

    uninitialized_copy(elements, first_free, newElements);

    for (T* p = first_free; p != elements; ) {
        alloc.destroy(--p);
    }

    if (elements)   /* not NULL */
        alloc.deallocate(elements, capacity());

    elements = newElements;
    first_free = elements + size;
    end = elements + newCapacity;
}

int main() {
    Vector<int> vec;
    vec.push_back(1);
    cout << "size= " << vec.size() << ", capacity= " << vec.capacity() << endl;
    vec.push_back(2);
    cout << "size= " << vec.size() << ", capacity= " << vec.capacity() << endl;
    vec.push_back(2);
    cout << "size= " << vec.size() << ", capacity= " << vec.capacity() << endl;
    vec.push_back(2);
    cout << "size= " << vec.size() << ", capacity= " << vec.capacity() << endl;
    vec.push_back(2);
    cout << "size= " << vec.size() << ", capacity= " << vec.capacity() << endl;
    vec.push_back(2);
    cout << "size= " << vec.size() << ", capacity= " << vec.capacity() << endl;
    vec.push_back(2);
    cout << "size= " << vec.size() << ", capacity= " << vec.capacity() << endl;
    vec.pop_back();
    return 0;
}
