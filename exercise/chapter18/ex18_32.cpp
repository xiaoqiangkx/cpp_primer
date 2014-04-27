#include <iostream>
#include <cassert>
using namespace std;

template <typename Type> class Queue;



template <typename T>
class Queue {
    public:
        Queue(): head(NULL), tail(NULL) {}
        ~Queue() {
            QueueItem *p = head;
            while (p != NULL) {
                QueueItem *q = p;
                p = p->next;
                delete(q);
            }
        }

        Queue(const Queue &queue) {
            QueueItem *p = NULL;
            for (p = head; p !=tail; p++) {
                push(p);
            }

            if (p != NULL) push(p);
        }

        Queue& operator=(const Queue &queue) {
            QueueItem *p = NULL;
            for (p = queue.head; p !=NULL; p = p->next) {
                push(p);
            }

        }

        void push(const T& item) {
           QueueItem *newItem = new QueueItem(item); 

           if (head == NULL) {
                head = newItem;
                tail = head;
           } else {
                tail->next = newItem;
                tail = newItem;
           }
        }

        void pop() {
           assert(head != NULL); 

           QueueItem *q = head;
           head = head->next;
           delete q;

           if (head == NULL) tail = NULL;
        }

        bool empty() const {
            return head == NULL;
        }

        const T& front() const {
            assert (head != NULL);
            return head->item;
        }

    private:
        struct QueueItem {
            T item;
            QueueItem *next;
            QueueItem(const T &_item): item(_item), next(NULL) {}
        };
        QueueItem *head;
        QueueItem *tail;
};

int main() {
    Queue<int> queue;
    cout << "empty: " << queue.empty() << endl;
    queue.push(1);
    cout << queue.front() << endl;
    queue.push(2);
    cout << queue.front() << endl;
    queue.pop();
    cout << queue.front() << endl;

    return 0;
}
