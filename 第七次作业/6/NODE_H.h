#ifndef NODE_H_H_INCLUDED
#define NODE_H_H_INCLUDED

//��ģ��Ķ���
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

//���ʵ�ֲ���
//���캯������ʼ�����ݺ�ָ���Ա
template<class T>
Node<T>::Node(const T& data,Node<T> *next/*=0*/):data(data),next(next){}

//���غ�̽���ָ��
template<class T>
Node<T> *Node<T>::nextNode(){
    return next;
}

//���غ�̽���ָ��
template<class T>
const Node<T> *Node<T>::nextNode() const{
    return next;
}

//�ڵ�ǰ���֮�����һ�����p
template<class T>
void Node<T>::insertAfter(Node<T> *p){
    p->next=next;
    next = p;
}

//ɾ����ǰ���ĺ�̽�㣬���������ַ
template<class T>
Node<T> *Node<T>::deleteAfter(){
    Node<T> *temptr=next;
    if(next==0)
        retrun 0;
    next=temptr->next;
    return temptr;
}

#endif // NODE_H_H_INCLUDED
