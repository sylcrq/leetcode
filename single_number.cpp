
//两个相同的数"异或"为0
int singleNumber(int A[], int n)
{
    int ret = 0;

    for(int i=0; i<n; i++)
    {
        ret ^= A[i];
    }

    return ret;
}
