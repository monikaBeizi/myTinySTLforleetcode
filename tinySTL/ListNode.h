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
    int length = 0;//保存链表的长度

    public:
    explicit NodeList():head(nullptr){}
    ~NodeList();//析构函数
    void insertFront(Type d);
    void insertBehind(Type d);
    void remove(Node<Type> &d);
    void remove(Type d);
    bool find(Type d);//查找
    void status(void);//打印链表
    void fill(void);
};

//析构函数
template<class Type>
NodeList<Type>::~NodeList()
{
    Node<Type> *p = head;  //将头节点的地址赋给指针变量p
    while (p !=nullptr)   //在p节点不是空指针的情况下一直循环，指导p指向空节点
    {
        Node<Type> *q = p->next; //将p节点的下一个节点的地址赋值给q指针
        delete p;   //释放掉p节点之前申请的内存
        p = q;     //将q节点的地址，也就是之前被释放掉内存的节点的内存重新赋给p节点
    }
} //析构函数在每次该类型被删除，比如说 代码运行出作用域的时候，编译器自动发挥作用？

//插入方法，向头节点前面插入，头节点后置，新来的节点是头节点
template<class Type>
void NodeList<Type>::insertFront(Type d)
{
    Node<Type> * newNode = new Node<Type>(d);//给新节点申请新的内存,这一行用到了Node类的制造函数，d是该新节点的data；
    newNode->next =head;  //将新申请的节点的next指针指向头节点之前的地址
    head=newNode;     //然后将头节点之前的指针指向该节点，也就是说把之前的头节点放在了后边。新节点是新的头节点
    length++;           //长度加一
}

//向后边插入
template<class Type>
void NodeList<Type>::insertBehind(Type d)
{
    Node<Type>* temp = head;
    if(head == nullptr)
    {
        head = new Node<Type>(d);
        return;
    }

    while(temp->next !=nullptr)//让指针temp不断循环直到最后一个链表
    {
        temp = temp->next;
    }

    temp->next = new Node<Type>(d);//在new的时候使用构造函数
    length ++;
}

//打印链表
template<class Type>
void NodeList<Type>::status(void)
{
    Node<Type>*temp = head;
    while(temp != nullptr)
    {
        std::cout<<temp->data<<",";
        temp = temp->next;
    }
}

//查找链表中是否存在某个元素，讲道理是不是还要整个返回下标的函数
template<class Type>
bool NodeList<Type>::find(Type d)
{
    Node<Type>* temp =head;
    while(temp != nullptr)
    {
        if(temp->data == d)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//删除节点
template<class Type>
void NodeList<Type>::remove(Node<Type> &d)//不过必须要直到其中某个节点才行，得整个删除具体数据的重载
{
    //等下如果输入的节点地址找不到的话，不久把head后面那个节点给删除了吗。bug啊，得改
    Node<Type>*temp = head;

    while(temp != nullptr)
    {
        if(temp ->next == &d)//从前往后找，如果有地址一样的节点就退出循环
        {
            break;
        }
    }

    Node<Type>*tempAnother = temp->next->next;
    delete temp->next;
    temp->next = tempAnother;
}

//删除节点，输入为data的重载函数
template<class Type>
void NodeList<Type>::remove(Type d)
{
    Node<Type>*temp = head;

    while(temp != nullptr)
    {
        if(temp->data == d)//从前往后找，如果有地址一样的节点就退出循环
        {
            break;
        }
    }

    Node<Type>*tempAnother = temp->next->next;
    delete temp->next;
    temp->next = tempAnother;
}




#endif