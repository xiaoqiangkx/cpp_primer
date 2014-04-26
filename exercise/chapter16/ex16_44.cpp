#include <iostream>
#include <list>
#include <cassert>
using namespace std;

template <typename T>
class Queue {
    public:
        Queue() {}

        Queue(const Queue &queue) {
            li.assign(queue.li.begin(), queue.li.end());
        }

        Queue& operator=(const Queue &queue) {
            li.assign(queue.li.begin(), queue.li.end());
        }

        void push(const T& item) {
            li.push_back(item);
        }

        void pop() {
            li.pop_front();
        }

        bool empty() const {
            return li.empty();
        }

        const T& front() const {
            return li.front();
        }

        const T& back() const {
            return li.back();
        }

    private:
        list<T> li;
};


template <typename T>
istream& operator>>(istream &is, Queue<T> &queue) {
    T data;
    is >> data;
    queue.push(data);
}

int main() {
    Queue<int> queue;
    cout << "empty: " << queue.empty() << endl;
    queue.push(1);
    cout << queue.front() << endl;
    queue.push(2);
    cout << queue.front() << endl;
    queue.pop();
    cout << queue.front() << endl;

    cin >> queue;
    cout << queue.back() << endl;
    return 0;
}
