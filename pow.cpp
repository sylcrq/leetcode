#include <math.h>
#include <stack>
//#include <iostream>
#include <stdlib.h>

using namespace std;

double pow(double x, int n)
{
    if(n == 0)
        return 1.0;

    bool negative = n < 0;

    //n = abs(n);  // Note: Overflow! abs(-2147483648)
    double result = x;

    stack<int> my_stack;

    while(n != 0)
    {
        my_stack.push(n);
        n = n / 2;
        // Note: if(n < 0), (n / 2) and (n >> 1) is different!
    }

    my_stack.pop();  // pop '1' or '-1'

    while(!my_stack.empty())
    {
        int tmp = my_stack.top();
        my_stack.pop();

        if(tmp % 2 == 0)
            result = result * result;
        else
            result = result * result * x;
    }

    if(negative)
    {
        // TODO: exception !
        // Note: double compare with 0
        if(fabs(result) < 10e-7)
            return -1.0;

        result = 1.0 / result;
    }

    return result;
}


