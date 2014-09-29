// Binary Search
// 由于存在相同元素, 特定情况下时间复杂度会退化为O(N)
bool search_ii(int A[], int n, int target) 
{
    if(n <= 0) return false;

    int left = 0;
    int right = n - 1;
    int mid = (left+right) >> 1;

    while(left <= right)
    {
        if(target == A[mid])
            return true;

        // [left, mid] is sorted
        if(A[mid] > A[left])
        {
            if(target >= A[left] && target < A[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        // [mid, right] is sorted
        else if(A[mid] < A[left])
        {
            if(target > A[mid] && target <= A[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
        else
        {
            left++;
        }

        mid = (left+right) >> 1;
    }

    return false;
}
