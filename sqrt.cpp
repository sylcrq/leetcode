#include <limits.h>

int sqrt(int x) 
{
    // invalid input
    if(x < 0) 
        return -1;

    if(x == 0) 
        return 0;

    int start = 1;
    int end = x;
    int mid = (start+end) / 2;

    // binary search
    while(start <= end)
    {
        mid = (start+end) / 2;

        // prevent overflow
        if(mid > (INT_MAX / mid))
        {
            end = mid - 1;
            continue;
        }

        int square = mid * mid;
        
        if(square == x)
        {
            return mid;
        }
        else if(square > x)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return (start+end) / 2;  // ?
}


