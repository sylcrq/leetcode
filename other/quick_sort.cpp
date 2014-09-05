#include <algorithm>
#include <iostream>
#include <stack>


int partition(int* array, int len)
{
    //选取第一个元素为基准
    int pivot = array[0];
    //比pivot小的元素的个数
    int counter = 0;

    for(int i=0; i<len; i++)
    {
        if(array[i] < pivot)
            counter++;
    }

    std::swap(array[0], array[counter]);

    int i = 0;
    int j = counter + 1;

    while(1)
    {
        while((array[i] < pivot) && (i < counter)) i++;
        while((array[j] >= pivot) && (j < len)) j++;

        if(i == counter || j == len)
            break;

        std::swap(array[i], array[j]);
    }

    return counter;
}

//快速排序 -- 递归
void quick_sort_recursive(int* array, int len)
{
    if(len == 1 || len == 0) return;

    int i = partition(array, len);

    quick_sort_recursive(array, i);
    quick_sort_recursive(array+i+1, len-i-1);
}

//快速排序 -- 非递归
void quick_sort(int* array, int len)
{
    if(len == 1 || len == 0) return;

    std::stack< std::pair<int, int> > my_stack;

    //初始状态压栈
    my_stack.push(std::make_pair(0, len));

    while(!my_stack.empty())
    {
        //栈顶元素出栈
        std::pair<int, int> info = my_stack.top();
        my_stack.pop();

        int i = partition(array+info.first, info.second);

        if(i > 1)
            my_stack.push(std::make_pair(info.first, i));
        
        if(info.second-i-1 > 1)
            my_stack.push(std::make_pair(info.first+i+1, info.second-i-1));
    }
}

