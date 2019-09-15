#ifndef LINKEDLIST_H_H_INCLUDED
#define LINKEDLIST_H_H_INCLUDED
#include"Node_H.h"

template<class T>
class LinkedList{
private:
    //数据成员:
    Node<T>*front,*rear;
    Node<T>*prevPtr,*currPtr;
    int size;
    int position;

    //函数成员
    //生成新的结点，数据域为item，指针域为ptrNext
    Node<T> *newNode(const T &item,Node<T> *pteNext=NULL);

    //释放结点
    void freeNode(Node<T> *p);

    //将链表L复制到当前表（假设当前表为空）
    //将复制构造函数和“operator=”调用
    void copy(const LinkedList<T> &L);

public:
    LinkedList();
    LinkedList(const LinkedList<T> &L);
    ~LinkedList();
    LinkedList<T> &operator=(const LinkedList<T> &L);

    int getSize() const;
    bool isEmpty() const;

    void reset(int pos=0);
    void next();
    bool endOfList() const;
    int currentPosition(void) const;

    void insertFront(const T &item);
    void insertRear(const T &item);
    void insertAt(const T &item);
    void insertAfter(const T &item);
    T deleteFront();
    void deleteCurrent();

    T& data();
    const T& data() const;

    //清空链表：释放所有结点的内存空间。被西析构函数和“operator=”调用
    void clear();
};


#endif // LINKEDLIST_H_H_INCLUDED
