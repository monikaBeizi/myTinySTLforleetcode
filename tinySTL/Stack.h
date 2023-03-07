//书上的示例
#ifndef STACKTP1_H_
#define STACKTP1_H_

#include<iostream>
#include<string>

using std::string;

template <class Type>
class Stack
{
    private:
    enum {SIZE = 10};
    int stackSize;
    Type * items;  //指针数组
    int top;        //栈顶

    public:
    explicit Stack(int ss = SIZE);  //定义构造函数，explicit为了防止隐式转换？我也不知道，但看别人这么加我也就这么整了
    Stack(const Stack & st);
    ~Stack(){delete [] items;}   //析构函数，用来清理申请的空间
    bool isempty(){return top == 0;}     
    bool isfull(){return top == stackSize;}
    bool push(const Type &item);
    bool pop(Type & item);
    Stack & operator = (const Stack &st);
    Stack & operator + (const Stack &st);
    void status(void);
    void fill(void);
};

//构造函数，ss为栈的长度
template <class Type>
Stack<Type>::Stack(int ss): stackSize(ss),top(0)
{
    items = new Type [stackSize];
}

//重构的构造函数，输入另外一个相同数据类型的栈就可以复制
template<class Type>
Stack<Type>::Stack(const Stack &st)
{
    stackSize = st.stackSize;
    top = st.top;
    items = new Type[stackSize];
    for(int i = 0;i < top; i++)
    {
        items[i] = st.items[i];
    }
}

//压入
template<class Type>
bool Stack<Type>::push(const Type &item)
{
    if(top < stackSize)
    {
        items[top++] = item;
        return true;
    }
    else
    {
        return false;
    }
}

//弹出
template<class Type>
bool Stack<Type>::pop(Type &item)
{
    if(top > 0)
    {
        item = items[--top];
        return true;
    }
    else
    {
        return false;
    }
}


//重载等于号
template<class Type>
Stack<Type>& Stack<Type>::operator=(const Stack<Type> &st)
{
    if(this == &st)
    return *this;
    delete [] items;
    stackSize = st.stackSize;
    top = st.top;
    items = new Type [stackSize];
    for (int i = 0;i <top; i++)
    items[i] = st.items [i];
    return *this;//返回Stack的引用可以实现连等于符号
}

template<class Type>
void Stack<Type>::status(void)
{
    //打印具体有多少元素
    std::cout<<"There are "<<top<<" element\n";

    //打印所有元素
    std::cout<<"The elements are as follows\n:";
    for(int i = 0;i <top;i++)
    {
        std::cout<<items[i]<<",";
    }
    std::cout<<"\n";
}

//向类中填充元素方便算法运行
template<class Type>
void Stack<Type>::fill(void)
{
    for(int i =0;i <stackSize;i++)
    {
        items[i] = i;
        top++;
    }
    std::cout<<"fill complete.\n";
}

// 向字符栈中填充字符。上面的只满足数字栈的情况，所以这个方法是用来填充字符“test”的
template<>
void Stack<string>::fill(void)
{
    for(int i = 0;i < stackSize;i++)
    {
        items[i] = "test";
        top++;
    }
    std::cout<<"char fill complete.\n";
}

// 重载+号
template<class Type>
Stack<Type>& Stack<Type>::operator+(const Stack<Type> & st)
{
    Type * temp;
    temp = new Type[stackSize + st.stackSize];
    for(int i = 0;i < top+st.top;i++)
    {
        if(i < top)
        temp[i] = items[i];
        else
        temp[i] = st.items[i - top];
    }
    top = top +st.top;
    stackSize = stackSize +st.stackSize;
    delete items;
    items = temp;
    return *this;
}
//不过这段有些缺陷，在+的时候就会改变左侧的数，不符合平常使用加号的逻辑

#endif
