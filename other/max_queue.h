#ifndef _MAX_QUEUE_
#define _MAX_QUEUE_


#include "max_stack.h"

class MaxQueue
{
public:
    void push(int n);
    void pop(void);
    int max(void);

private:
    //用两个栈实现队列
    MaxStack max_stack_a_;
    MaxStack max_stack_b_;
};


#endif
