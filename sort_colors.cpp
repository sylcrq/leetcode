#include <algorithm>
#include <string.h>


//two-pass 
void sortColors(int A[], int n)
{
    int red_num = 0;
    int white_num = 0;
    int blue_num = 0;

    for(int i=0; i<n; i++)
    {
        if(0 == A[i])  // RED
            red_num++;
        else if(1 == A[i])  // WHITE
            white_num++;
        else if(2 == A[i])  // BLUE
            blue_num++;
    }

    for(int i=0; i<red_num; i++)
    {
        A[i] = 0;  // RED
    }

    for(int i=red_num; i<red_num+white_num; i++)
    {
        A[i] = 1;  // WHITE
    }

    for(int i=red_num+white_num; i<n; i++)
    {
        A[i] = 2;  // BLUE
    }
}

//one-pass
void sortColors_2(int A[], int n)
{
    int red = 0;
    int blue = n-1;
    int i = 0;

    while(i <= blue)
    {
        if(0 == A[i])  // RED
        {
            std::swap(A[i], A[red]);
            red++;
            i++;
        }
        else if(1 == A[i])  // WHITE
        {
            i++;
        }
        else if(2 == A[i])  // BLUE
        {
            std::swap(A[i], A[blue]);
            blue--;
        }
    }
}

