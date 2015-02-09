#include <algorithm>

int findKthSortedArrays(int A[], int m, int B[], int n, int k);

double findMedianSortedArrays(int A[], int m, int B[], int n) 
{
    if(m < 0 || n < 0 || (m+n) <= 0)
        return 0;

    if((m+n) & 0x1)  // odd
        return findKthSortedArrays(A, m, B, n, (m+n)/2);
    else  // even
        return ( (findKthSortedArrays(A, m, B, n, (m+n)/2) + 
                  findKthSortedArrays(A, m, B, n, (m+n)/2 - 1)) / 2.0 );
}


// find the Kth element of two sorted arrays
// (K started from 0)
// A[0], ..., A[m/2], A[m/2+1], ..., A[m]
// B[0], ..., B[n/2], B[n/2+1], ..., B[n]
int findKthSortedArrays(int A[], int m, int B[], int n, int k)
{
    if(m <= 0)
        return B[k];

    if(n <= 0)
        return A[k];

    if(k <= 0)
        return std::min(A[0], B[0]);

    if(k > (m/2) + (n/2))
    {
        if(A[m/2] > B[n/2])
            return findKthSortedArrays(A, m, B+(n/2)+1, n-(n/2)-1, k-(n/2)-1);  // ignore first half of B
        else
            return findKthSortedArrays(A+(m/2)+1, m-(m/2)-1, B, n, k-(m/2)-1);  // ignore first half of A
    }
    else
    {
        if(A[m/2] > B[n/2])
            return findKthSortedArrays(A, m/2, B, n, k);  // ignore second half of A
        else
            return findKthSortedArrays(A, m, B, n/2, k);  // ignore second half of B
    }
}

