#include <iostream>
using namespace std;

template <typename T>
struct ListNode {
    ListNode *next;
    T val;
    ListNode(const T &_val): next(NULL), val(_val) {} 
};

template <typename T>
class List {
    // 默认构造函数
    List(): head(NULL) {}

    List(const List&);
    List& operator=(const List&);
    ~List();

    void insert(T *ptr, const T &val);
    void del(T *ptr);
    Type *find(const T &val);
    Type& getElem(T *ptr);
    bool empty() const;

    private:
        ListNode *head; 
};
