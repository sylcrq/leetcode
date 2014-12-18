#include <algorithm>
#include <iostream>

void print_c_array(int array[], int n);

int firstMissingPositive(int A[], int n) 
{
    for(int i=0; i<n; i++)
    {
        while(A[i] != i+1)
        {
            if(A[i] <= 0 || A[i] > n || A[i] == A[A[i]-1])
                break;

            std::swap(A[i], A[A[i]-1]);
            //print_c_array(A, n);
        }
    }

    for(int i=0; i<n; i++)
    {
        if(A[i] != i+1)
            return (i+1);
    }

    return (n+1);
}

void print_c_array(int array[], int n)
{
    for(int i=0; i<n; i++)
    {
        std::cout << array[i] << ", ";
    }

    std::cout << std::endl;
}
