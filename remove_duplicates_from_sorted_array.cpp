#include <iostream>

//时间复杂度O(n^2)
int removeDuplicates(int A[], int n)
{
    int len = n;

    for(int i=0; i<len-1; )
    {
        if(A[i] == A[i+1])
        {
            for(int j=i; j<len-1; j++)
                A[j] = A[j+1];

            len--;
            i = 0;
        }
        else
        {
            i++;
        }
    }

    //for(int i=0; i<len; i++)
    //{
    //    std::cout << A[i] << ",";
    //}
    //std::cout << std::endl;

    return len;
}

int removeDuplicates_2(int A[], int n)
{
    int steps = 0;

    //A[i]与A[i+1]比 or A[i]与A[i-1]比
    //两种情况处理起来不同
    for(int i=1; i<n; i++)
    {
        if(A[i] == A[i-1])
            steps++;
        else
            A[i-steps] = A[i];
    }

    //for(int i=0; i<n-steps; i++)
    //{
    //    std::cout << A[i] << ", ";
    //}
    //std::cout << std::endl;

    return (n - steps);
}

//int removeDuplicates_yingl(int A[], int n) {
//    int steps;
//
//    for (int i = 1; i < n; ++i) {
//        if (A[i] == A[i - 1]) {
//            ++steps;
//        }
//        else {
//            A[i - steps] = A[i];
//        }
//    }
//
//    return n - steps;
//}

