#include <string>
#include <stack>

using namespace std;

// 栈匹配
bool isValid(string s)
{
    stack<char> my_stack;

    for(size_t i=0; i<s.size(); i++)
    {
        if(my_stack.empty())
        {
            my_stack.push(s[i]);
        }
        else
        {
            char c = my_stack.top();

            if((s[i] == ')' && c == '(') || 
               (s[i] == ']' && c == '[') ||
               (s[i] == '}' && c == '{'))
            {
                my_stack.pop();
            }
            else
            {
                my_stack.push(s[i]);
            }
        }
    }

    if(!my_stack.empty())
        return false;

    return true;
}
