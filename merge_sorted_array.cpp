
// You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B.
// The number of elements initialized in A and B are m and n respectively.
void merge(int A[], int m, int B[], int n)
{
    // 从后往前合并
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while(i>=0 && j>=0)
    {
        if(A[i] > B[j])
        {
            A[k] = A[i];
            i--;
        }
        else
        {
            A[k] = B[j];
            j--;
        }

        k--;
    }

    // 优化
    //while(i>=0)
    //{
    //    A[k] = A[i];
    //    i--;
    //    k--;
    //}

    while(j>=0)
    {
        A[k] = B[j];
        j--;
        k--;
    }
}
