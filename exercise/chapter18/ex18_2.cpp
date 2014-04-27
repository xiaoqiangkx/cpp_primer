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
        typedef T* iterator;
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
        void reserve(size_t n);
        void resize(size_t n, const T& t = T());

        iterator begin() const {
            return elements;
        }

        iterator last() const {
            return first_free;
        }

        T& operator[](const size_t index) {
            if (elements + index >= first_free) {
                throw out_of_range("out of range");
            }

            return *(elements + index);
        }


    private:
        static allocator<T> alloc;  /* just a declaration */
        T* elements;
        T* first_free;
        T* end;

        void reallocate();
};

template <typename T> allocator<T> Vector<T>::alloc;    /* must have this */


// onl if n > capacity, it cause reallocate
template <typename T>
void Vector<T>::reserve(size_t n) {
    int size = Vector<T>::size();
    if (n > capacity()) {
        int newCapacity = n;

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
}

// change the size of elements
template <typename T>
void Vector<T>::resize(size_t n, const T& t) {
   if (n <= capacity()) {
       /* destory */
       for (int i=size()-1; i>=n; i--) {
           alloc.destroy(elements + i); /* destroy from back to front */
       }       

       /* initialization */
       for (int i=size(); i<n; i++) {
          alloc.construct(elements + i, t); 
       }

       /* ?? I can just delete some of the data */
       /* deallocate */
//       if (capacity() - n > 0) {
//         T* p = elements + n; 
//           alloc.deallocate(p, capacity() - n);
//       }
       first_free = elements + n;

   } else {
       int newSize = size();
       int newCapacity = n;
       T* newElements = alloc.allocate(newCapacity);

       uninitialized_copy(elements, first_free, newElements);

       for (T* p = first_free; p != elements; ) {
           alloc.destroy(--p);
       }

       if (elements)   /* not NULL */
           alloc.deallocate(elements, capacity());

       elements = newElements;
       first_free = elements + newSize;
       end = elements + newCapacity;
          
       while (first_free != end) {
           alloc.construct(first_free, t);
           first_free++;
       }
   } 
}

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

    vec.reserve(8);
    cout << "size= " << vec.size() << ", capacity= " << vec.capacity() << endl;
    vec.reserve(10);
    cout << "size= " << vec.size() << ", capacity= " << vec.capacity() << endl;

    vec.resize(20, 1);
    cout << "size= " << vec.size() << ", capacity= " << vec.capacity() << endl;
    vec.resize(4, 1);
    cout << "size= " << vec.size() << ", capacity= " << vec.capacity() << endl;
    return 0;
}
