#include "gtest/gtest.h"
#include "implement_stack_using_queues.h"

TEST(ImplementStackUsingQueuesTestCase, Normal) {
    Stack stack;
    stack.print_debug();

    stack.push(1);
    stack.print_debug();

    stack.push(2);
    stack.print_debug();

    stack.push(3);
    stack.print_debug();

    stack.pop();
    stack.print_debug();

    stack.push(4);
    stack.print_debug();
}
