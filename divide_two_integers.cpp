#include <limits.h>
//#include <stdlib.h>
//#include <iostream>

int divide(int dividend, int divisor) 
{
    // math error
    if(divisor == 0)
        return INT_MAX;

    // overflow
    if(dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    if(dividend == 0)
        return 0;

    bool positive = true;
    if( (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) )
        positive = true;
    else
        positive = false;

    // Note: abs(INT_MIN) = INT_MIN
    unsigned int divd = (dividend > 0) ? dividend : dividend*(-1);
    unsigned int divs = (divisor > 0) ? divisor : divisor*(-1);

    if(divs == 1)
        return (positive ? divd : divd*(-1));

    if(divd == divs)
        return (positive ? 1 : -1);

    if(divd < divs)
        return 0;

    int result = 0;
    while(divd >= divs)
    {
        int i = 1;
        int j = 0;
        while((divd >> (j+1)) >= divs)
        {
            i = i << 1;
            j++;
        }
        
        if((divd >> j) >= divs)
        {
            result += i;
            divd = divd - (divs << j);
        }
    }

    return (positive ? result : result*(-1));
}

