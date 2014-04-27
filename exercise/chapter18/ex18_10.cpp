#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
using namespace std;

template <typename T>
class CachedObj {
    public:
        void* operator new(size_t);
        void operator delete(void *, size_t);
        ~CachedObj() {}
    protected:
        T *next;    /* let T to get next */
    private:
        static void add_to_freelist(T*);
        static allocator<T> alloc;
        static T* freeStore;
        static const size_t chunck; /* get chunck of memory */
};

template <typename T>
allocator<T> CachedObj<T>::alloc;

template <typename T>
T* CachedObj<T>::freeStore = NULL;

template <typename T>
const size_t CachedObj<T>::chunck = 24;

template <typename T>
void* CachedObj<T>::operator new(size_t n) {
    if (n != chunck) {
       throw new runtime_error("CachedObj: wrong size object in operator new"); 
    }

    if (freeStore == NULL) {
        T *array = alloc.allocate(chunck);
        for (size_t i = 0; i<chunck; i++) {
            add_to_freelist(&array[i]);
        }
    }

    T* p = freeStore;
    freeStore = freeStore->CachedObj<T>::next;  /* next */
    return p;
}

template <typename T>
void CachedObj<T>::operator delete(void* p, size_t n) {
    if (p != 0) {
        add_to_freelist(static_cast<T*>(p));
    }
}

template <typename T>
void CachedObj<T>::add_to_freelist(T *p) {
    p->CachedObj<T>::next = freeStore;
    freeStore = p;
}

template <typename T>
class QueueItem: public CachedObj<QueueItem <T> > {
    public:
        QueueItem(const T& t, const string& name="")
            : price(t), isbn(name) {}

    private:
        string isbn;
        T price;
};

int main() {
    QueueItem<double> *p = new QueueItem<double>(2.0, "123");
    delete p;
    return 0;
}
