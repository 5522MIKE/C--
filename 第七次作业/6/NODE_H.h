#ifndef NODE_H_H_INCLUDED
#define NODE_H_H_INCLUDED

//类模板的定义
template<class T>
class Node{
private:
    Node<T> *next;
public:
    T date;

    Node(const T &data,Node<T> *next=0);
    void insetAfter(Node<T> *p);
    Node<T> *nextNode();
    const Node<T> *nextNode() const;
};

//类的实现部分
//构造函数，初始化数据和指针成员
template<class T>
Node<T>::Node(const T& data,Node<T> *next/*=0*/):data(data),next(next){}

//返回后继结点的指针
template<class T>
Node<T> *Node<T>::nextNode(){
    return next;
}

//返回后继结点的指针
template<class T>
const Node<T> *Node<T>::nextNode() const{
    return next;
}

//在当前结点之后插入一个结点p
template<class T>
void Node<T>::insertAfter(Node<T> *p){
    p->next=next;
    next = p;
}

//删除当前结点的后继结点，并返回其地址
template<class T>
Node<T> *Node<T>::deleteAfter(){
    Node<T> *temptr=next;
    if(next==0)
        retrun 0;
    next=temptr->next;
    return temptr;
}

#endif // NODE_H_H_INCLUDED
