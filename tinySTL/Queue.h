//是这项tingstl第一个，主要目的是写一段可以重复利用，功能齐全的队列的代码 
// 这样方便自己刷leetcode的题目

#ifndef QUEUEP1_H_
#define QUEUEP1_H_
// 目前还没有完全掌握代码复用的知识，先暂时用template支持相关功能，后续补全
#include<iostream>
#include<string>

// queue类单向队列（头出后进）,数组组成

// 用非类型参数还是在构造函数中？

using std::string;


//顺序储存队列
template<class Type>
class Queue
{
    private:
    enum{SIZE = 10};//如果构造函数没有输入大小则使用这个
    int queueSize;
    Type * items;
    int length;
    int front;
    int rear;

    public:
    explicit Queue(int qs = SIZE);
    Queue(const Queue &qu);
    ~Queue(){delete [] items;};
    bool isempty(){return length == 0;}
    bool isfull(){return length == queueSize;}
    bool push(const Type &item);
    bool pop(Type & item);
    Queue& operator=(const Queue &qu);
    void fill(void);
    void status(void);

};

//构造函数1，括号内输入队列大小
template<class Type>
Queue<Type>::Queue(int qs): queueSize(qs),length(0),front(0),rear(0)
{
    items = new Type [queueSize];
}

template<class Type>
Queue<Type>::Queue(const Queue &qu)
{
    queueSize = qu.queueSize;
    length = qu.length;
    items = new Type[queueSize];
    front = qu.front;
    rear = qu.rear;
    for(int i =0;i<length;i++)
    {
        items[i] = qu.items[i];
    }
}

//因为都是用数组指针指向相应的，所以可以通用代码
template<class Type>
bool Queue<Type>::push(const Type &item)
{
    if(rear < queueSize)
    {
        //rear指针是指向没有被赋值的空位
        items[rear++] = item;
        length ++;
        return true;
    }
    else
    {
        return false;        
    }
}

template<class Type>
bool Queue<Type>::pop(Type &item)
{
    if(length > 0 && front >= 0 && front <= rear )
    {
        item = items[front++];
        length--;
        return true;
    }
    else
    {
        return false;
    }
}

//重载等于号
template<class Type>
Queue<Type>& Queue<Type>::operator=(const Queue<Type> &qu)
{
    if(this == &qu)
    return *this;
    delete [] items;
    queueSize = qu.queueSize;
    length = qu.length;
    front = qu.front;
    rear = qu.rear;
    items = new Type[queueSize];
    for(int i = 0;i < length;i++)
    items [i] =qu.item;
    return *this;
}

template<class Type>
void Queue<Type>::status(void)
{
    std::cout<<"There are "<<length<<" elements.\n";

    //打印所有元素
    std::cout<<"The elements are as follows:\n";
    for(int i = front;i <rear; i++)
    {
        std::cout<<items[i]<<",";
    }
    std::cout<<"\n";
}


//向队列里面填充从零开始递增的数
template<class Type>
void Queue<Type>::fill(void)
{
    for(int i = 0;i < queueSize; i++)
    {
        items[i] = i;
        length ++;
        rear ++;
    }
    std::cout<<"fill complete. \n";
}

//显式具体化
template<>
void Queue<string>::fill(void)
{
    for(int i = 0;i < queueSize;i ++)
    {
        items[i] = "test";
        length ++;
        rear++;
    }
    std::cout<<"char fill complete.\n";
}

#endif 