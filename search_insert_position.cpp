
// 遍历 - O(N)
int searchInsert(int A[], int n, int target)
{
    int i = 0;

    for(i=0; i<n; i++)
    {
        if(A[i] >= target)
            break;
    }

    return i;
}

// 二分 - O(logN)
int searchInsert_ii(int A[], int n, int target)
{
    if(n == 0) return 0;

    int start = 0;
    int end = n-1;
    int mid = (start + end) / 2;

    while(start <= end)
    {
        if(A[mid] == target)
        {
            return mid;
        }
        else if(A[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = (start + end) / 2;
    }

    return (end + 1);
}
