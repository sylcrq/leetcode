// solution 1
int removeDuplicates_ii(int A[], int n) 
{
    int steps = 0;
    bool flag = false;

    for(int i=1; i<n; i++)
    {
        if(A[i] == A[i-1])
        {
            if(flag)
            {
                steps++;
            }
            else
            {
                flag = true;
            }
        }
        else
        {
            flag = false;
        }

        A[i - steps] = A[i];
    }

    return (n - steps);
}

// solution 2
int removeDuplicates_ii_v2(int A[], int n)
{
    if(n <= 1) return n;

    int index = 0;
    int flag = 1;

    for(int i=1; i<n; i++)
    {
        if(A[index] == A[i])
        {
            if(flag == 2)
            {
                continue;
            }
            else
            {
                flag++;
            }
        }
        else
        {
            flag = 1;
        }

        index++;
        A[index] = A[i];
    }

    return index + 1;
}

