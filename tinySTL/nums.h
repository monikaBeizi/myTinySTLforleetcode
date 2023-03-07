#ifndef NUMSP1_H_
#define NUMSP1_H_

#include<iostream>

// template<class Type,size_t N>
// void insertSortPositive(Type (& arr)[N])
// {

//     //N是整个数组的大小
//     int i;

//     for(i = 1;i < N; i++)
//     {
//         if(arr[i-1]>arr[i])
//         {
//             int tempForj = 0;
//             int temp = arr[i];
//             for( int j = i -1;j>=0 && temp < arr[j];j--)//这里用temp而不是用arr[i]可以防止在前移的过程中，arr[i]的数值被改变而影响结果
//             {
//                 arr[j+1] = arr[j];
//                 if(j-1 >= 0 && temp < arr[j -1])
//                 {
//                     tempForj = j -1;
//                 }
//             }
//             arr[tempForj+1] = temp;
//         }
//     }
// }

// template<class Type,size_t N>
// void insertSortReverse(Type (&arr)[N])
// {
//     int i;
//     for(i = 1;i < N;i ++)
//     {
//         if(arr[i-1]<arr[i])
//         {
//             int temp=arr[i];
//             int tempForj = 0;
//             for(int j = i-1;j>= 0 && temp > arr[j];j--)
//             {
//                 arr[j+1] = arr[j];
//                 if(j - 1>=0 && temp > arr[j -1])
//                 {
//                     tempForj =j-1;
//                 }
//             }
//             arr[tempForj+1] = temp;
//         }
//     }
// }

template<class Type,size_t N>
void insertSortPositive(Type (&arr)[N])
{
    int i,j,temp;
    for(i = 1;i < N; i ++)
    {
        if(arr[i]<arr[i -1])
        {
            temp = arr[i];
            for( j =i -1;j >=0 && arr[j] > temp;--j)
            {
                arr[j+1]=arr[j];
            }
            arr[j+1] = temp;
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