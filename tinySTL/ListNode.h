#ifndef LISTNODEP1_H_
#define LISTNODEP1_H_
#include<iostream>
#include<string>

using std::string;

//定义结点
template<class Type>
class Node
{
public:
    Type data;//数据
    Node *next;
    Node(Type d,Node *n =nullptr): data(d),next(n){}
};

//定义链表类List
template<class Type>
class NodeList
{
    private:
    Node<Type>*head;

    public:
    explicit NodeList():head(nullptr){}
    ~NodeList();//析构函数
    void insertFront(Type d);
    void remove(Type d);
    bool find(Type d);//查找
    void status(void);//打印链表
};

//析构函数
template<class Type>
NodeList<Type>::~NodeList()
{
    Node<Type> *p = head;
    while (p !=nullptr)
    {
        Node<Type> *q = p->next;
        delete p;
        p = q;
    }
}

//插入方法，头节点不变
template<class Type>
void NodeList<Type>::insertFront(Type d)
{
    Node<Type> * newNode = new Node<Type>(d);
    newNode->next =head;
    head=newNode;
}



#endif