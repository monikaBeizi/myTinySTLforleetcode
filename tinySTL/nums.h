#ifndef NUMSP1_H_
#define NUMSP1_H_

#include<iostream>
//插入排序
template<class Type,size_t N>
void insertSortPositive(Type (&arr)[N])
{
    int i,j,temp;
    for(i = 1;i < N; i ++)//每次循环都是以前面已经是正序为基础的插入排序，或者说每次插入都是往前面正序里找到一个合适的位置
    {
        if(arr[i]<arr[i -1])//如果找到前面元素大于后边元素
        {
            temp = arr[i];//将该往前调的元素提出来，空出位置让前面大的数后移，给这个数腾地
            for( j =i -1;j >=0 && arr[j] > temp;--j)
            {
                arr[j+1]=arr[j];//后挪的具体操作，当arr【j】不再大于temp也就是移动之前的a【i】数，就结束移动
            }
            arr[j+1] = temp;//将这个数放在位移之后刚好空出来的地方。
        }
    }
}

template<class Type,size_t N>
void insertSortReverse(Type (&arr)[N])
{
    int i,j,temp;
    for(i = 1;i < N;i++)
    {
        if(arr[i]>arr[i -1])
        {
            temp = arr[i];
            for(j=i-1;j>=0 && arr[j] < temp;--j)
            {
                arr[j+1]=arr[j];
            }
            arr[j+1] = temp;
        }
    }
}


#endif