#include "max_stack.h"


void MaxStack::push(int n)
{
    stack_.push(n);

    if(max_stack_.empty())
        max_stack_.push(n);
    else if(n > max_stack_.top())
        max_stack_.push(n);
}

void MaxStack::pop(void)
{
    if(stack_.empty()) return;

    if(max_stack_.empty())
    {
        stack_.pop();
        return;
    }

    if(stack_.top() == max_stack_.top())
        max_stack_.pop();

    stack_.pop();
}

int MaxStack::max(void)
{
    if(max_stack_.empty())
        return 0;

    //Note: 空stack调用top()段错误
    return max_stack_.top();
}
    
bool MaxStack::empty(void)
{
    return stack_.empty();
}

int MaxStack::top(void)
{
    if(stack_.empty())
        return 0;

    return stack_.top();
}
