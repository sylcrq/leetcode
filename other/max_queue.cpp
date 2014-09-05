#include "max_queue.h"
    
void MaxQueue::push(int n)
{
    max_stack_a_.push(n);
}

void MaxQueue::pop(void)
{
    if(max_stack_b_.empty())
    {
        //Stack B为空
        //Stack A中元素pop,并push到Stack B中
        //Stack B pop
        while(!max_stack_a_.empty())
        {
            int n = max_stack_a_.top();
            max_stack_b_.push(n);
            max_stack_a_.pop();
        }

        max_stack_b_.pop();
    }
    else
    {
        max_stack_b_.pop();
    }
}

int MaxQueue::max(void)
{
    int a = max_stack_a_.max();
    int b = max_stack_b_.max();

    return (a > b) ? a : b;
}
