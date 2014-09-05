#ifndef _MAX_STACK_
#define _MAX_STACK_

#include <stack>

class MaxStack
{
public:
    void push(int n);
    void pop(void);
    int max(void);
    
    bool empty(void);
    int top(void);

private:
    std::stack<int> stack_;  //数据元素stack
    std::stack<int> max_stack_;  //最大元素stack
};


#endif
