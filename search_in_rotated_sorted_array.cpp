// Binary Search
int search(int A[], int n, int target)
{
    if(n <= 0) return -1;

    int left = 0;
    int right = n - 1;
    int mid = (left+right) >> 1;

    while(left <= right)
    {
        if(A[mid] >= A[left])  // [left, mid] is sorted
        {
            if(target == A[mid])
                return mid;
            else if(target >= A[left] && target < A[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else  // [mid, right] is sorted
        {
            if(target == A[mid])
                return mid;
            else if(target > A[mid] && target <= A[right])
                left = mid + 1;
            else
                right = mid - 1;
        }

        mid = (left+right) >> 1;
    }

    return -1;
}

