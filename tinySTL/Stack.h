//书上的示例
#ifndef STACKTP1_H_
#define STACKTP1_H_
template <class Type>
class Stack
{
    private:
    enum {SIZE = 10};
    int stackSize;
    Type * items;
    int top;

    public:
    explicit Stack(int ss = SIZE);
    Stack(const Stack & st);
    ~Stack(){delete [] items;}
    bool isempty(){return top == 0;}
    bool isfull(){return top == stackSize;}
    bool push(const Type &item);
    bool pop(Type & item);
    Stack & operator = (const Stack &st);
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
#endif
