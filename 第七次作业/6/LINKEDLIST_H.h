#ifndef LINKEDLIST_H_H_INCLUDED
#define LINKEDLIST_H_H_INCLUDED
#include"Node_H.h"

template<class T>
class LinkedList{
private:
    //���ݳ�Ա:
    Node<T>*front,*rear;
    Node<T>*prevPtr,*currPtr;
    int size;
    int position;

    //������Ա
    //�����µĽ�㣬������Ϊitem��ָ����ΪptrNext
    Node<T> *newNode(const T &item,Node<T> *pteNext=NULL);

    //�ͷŽ��
    void freeNode(Node<T> *p);

    //������L���Ƶ���ǰ�����赱ǰ��Ϊ�գ�
    //�����ƹ��캯���͡�operator=������
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

    //��������ͷ����н����ڴ�ռ䡣�������������͡�operator=������
    void clear();
};


#endif // LINKEDLIST_H_H_INCLUDED
