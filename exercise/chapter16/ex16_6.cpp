#include <iostream>
#include <deque>
using namespace std;

template <typename T>
class Queue {
    public:
        void push(const T &val);    /* more const */
        void pop();
        T& front();
        bool empty() const;     /* more const */
    private:
        deque<T> deq; 
};

template <typename T>
void Queue<T>::push(const T&val) {
    deq.push_back(val);
}

template <typename T>
void Queue<T>::pop() {
    deq.pop_front();
}

template <typename T>
T& Queue<T>::front() {
    return deq.front();
}

template <typename T>
bool Queue<T>::empty() const {
    return deq.empty();
}

int main() {
    Queue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.pop();
    int b = queue.front();
    queue.pop();

    bool isEmpty = queue.empty();
    return 0;
}
