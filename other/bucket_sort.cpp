#include <iostream>
#include <list>
#include <vector>

using namespace std;

/* 桶排序:
 * http://zh.wikipedia.org/wiki/桶排序
 */

int g_bucket_num = 10;

// 插入排序
void bucket_insert(list<int>& mylist, int num)
{
    for(list<int>::iterator it=mylist.begin(); it != mylist.end(); it++)
    {
        if(num < (*it))
        {
            mylist.insert(it, num);
            return;
        }
    }

    mylist.insert(mylist.end(), num);
}

// 归并排序
void bucket_merge(list<int>& list1, list<int>& list2)
{
    list<int>::iterator it1 = list1.begin();
    list<int>::iterator it2 = list2.begin();
    
    while(it1 != list1.end() && it2 != list2.end())
    {
        if((*it1) > (*it2))
        {
            it1 = list1.insert(it1, *it2);
            it1++;
            it2++;
        }
        else
        {
            it1++;
        }
    }

    if(it1 == list1.end() && it2 != list2.end())
    {
        list1.insert(list1.end(), it2, list2.end());
    }
}

// 对数值范围在[0, 100)的数组进行bucket sort
void bucket_sort(vector<int>& array)
{
    int n = array.size();

    vector<list<int> > bucket(g_bucket_num);

    // 数据分类放到不同桶中(插入排序)
    for(int i=0; i<n; i++)
    {
        bucket_insert(bucket[array[i]/g_bucket_num], array[i]);
    }

    // 将桶分别合并到第一个桶中(归并排序)
    for(int i=1; i<g_bucket_num; i++)
    {
        bucket_merge(bucket[0], bucket[i]);
    }

    int i = 0;
    for(list<int>::iterator it=(bucket[0]).begin(); it != (bucket[0]).end(); it++)
    {
        array[i++] = *it;
    }
}

