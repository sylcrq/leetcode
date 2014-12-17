#include <iostream>
#include <vector>

using namespace std;

// 对范围在[0, 100)的数组进行Counting Sort
vector<int> counting_sort(vector<int>& array)
{
    int n = array.size();

    vector<int> count(100, 0);
    vector<int> sorted(n, 0);

    for(int i=0; i<n; i++)
    {
        count[array[i]]++;
    }

    for(int i=1; i<100; i++)
    {
        count[i] += count[i-1];
    }

    for(int i=n-1; i>=0; i--)
    {
        sorted[count[array[i]]-1] = array[i];
        count[array[i]]--;
    }

    return sorted;
}

void my_print_vector(vector<int>& array)
{
    for(vector<int>::iterator it=array.begin(); it != array.end(); it++)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}
