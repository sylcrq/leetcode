#include <string>

using namespace std;

// 动态规划
int numDecodings(string s) 
{
    if(s.empty())
        return 0;

    int size = s.size();

    // invalid num
    if(s[0] == '0')
        return 0;

    int result = 1;
    int prev = 1;
    int pprev = 1;

    for(int i=1; i<size; i++)
    {
        if(s[i] == '0' && s[i-1] != '1' && s[i-1] != '2')
            return 0;  // invalid num
        else if(s[i] == '0' && (s[i-1] == '1' || s[i-1] == '2'))
            result = pprev;  // f(n) = f(n-2)
        else if((s[i-1] == '1' && s[i] >= '1' && s[i] <= '9') || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6'))
            result = prev + pprev;  // f(n) = f(n-1) + f(n-2)
        else
            result = prev;  // f(n) = f(n-1)

        // update prev & pprev
        pprev = prev;
        prev = result;
    }

    return result;
}

