#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

template <typename T> class List;

template <typename T>
class ListNode {
    // template <typename Type> friend class List;
    friend class List<T>;
    T val;
    ListNode *prev;
    ListNode *next;
    ListNode(const T& _val): val(_val), prev(NULL), next(NULL) {}
};

template <typename T>
class List {
    public:

       template <typename IT>
       List(IT st, IT ed);

       template <typename IT>
       void assign(IT st, IT ed);

       List(): head(NULL), tail(NULL) {}
       ~List() {
           destroy();
       }

       List(const List &list) {
           ListNode<T> *newNode = NULL;
           ListNode<T> *p = list.head;
           while (p != NULL) {
               newNode = new ListNode<T>(p->val);

               if (head == NULL) {
                   head = newNode;
                   tail = head;
               } else {
                   tail->next = newNode;
                   tail = newNode;
               }
               p = p->next;
           }
       }

       List& operator=(const List& list) {
           ListNode<T> *newNode = NULL;
           ListNode<T> *p = list.head;
           while (p != NULL) {
               newNode = new ListNode<T>(p->val);

               if (head == NULL) {
                   head = newNode;
                   tail = head;
               } else {
                   tail->next = newNode;
                   tail = newNode;
               }
               p = p->next;
           }

           return *this;
       }

       bool isEmpty() const {
           return head == NULL;
       }

       T front() const {
           assert(head != NULL);
           return head->val;
       }

       T back() const {
           assert(tail != NULL);
           return tail->val;
       }

       void push(const T& val) {
           ListNode<T> *newNode = new ListNode<T>(val);
           if (tail == NULL) {
               head = newNode;
               tail = newNode;
           } else {
               tail->next = newNode;
               tail = newNode;
           }
       }


       void pop() {
           assert (head != NULL);
           ListNode<T> *q = head;
           head = head->next;
           delete q;

           // take care
           if (head == NULL) tail = NULL;
       }

       size_t size() const {
            ListNode<T> *p = head;
            size_t len = 0;
            while (p != NULL) {
                len++;
                p = p->next;
            }

            return len;
       }
    private:
       ListNode<T> *head;
       ListNode<T> *tail;
       void destroy() {
            ListNode<T> *p = head;
            ListNode<T> *q = NULL;
            while (p != NULL) {
                q = p;
                p = p->next;
                delete q;
            }
       }

};

template <typename Type> template <typename IT>
List<Type>::List(IT st, IT ed): head(NULL), tail(NULL) {    /* 构造函数需要初始化, 由于需要通过head==NULL判断非空 */
    while (st != ed) {
        push(*st);
        st++;
    }
}

template <typename Type> template <typename IT>
void List<Type>::assign(IT st, IT ed) {
    destroy();
    while (st != ed) {
        push(*st);
        st++;
    }
}


int main() {

    List<int> list;
    list.push(2);
    cout << list.front() << " " << list.back() << ",size= " << list.size() << endl;
    list.push(1);
    list.pop();
    cout << list.front() << " " << list.back() << ",size= " << list.size() << endl;

    int b[] = { 4, 5, 2, 1, 3};
    vector<int> a(b, b+5);
    List<int> list2(a.begin(), a.end());
    cout << list2.front() << " " << list2.back() << ",size= " << list2.size() << endl;
    list.assign(b, b+5);
    cout << list.front() << " " << list.back() << ",size= " << list.size() << endl;
    return 0;
}
