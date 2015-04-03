#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int longestValidParentheses(string s) 
{
    int max = 0;
    const char* pstr = s.c_str();
    const char* p = pstr;
    stack<const char*> my_stack;

    while(*p != '\0')
    {
        if(*p == '(')
        {
            my_stack.push(p);
        }
        else if(*p == ')')
        {
            if(!my_stack.empty() && *(my_stack.top()) == '(')
            {
                my_stack.pop();

                int len = my_stack.empty() ? (p-pstr+1) : (p-my_stack.top());
                // update max
                max = std::max(max, len);
            }
            else
            {
                my_stack.push(p);
            }
        }

        p++;
    }

    return max;
}

