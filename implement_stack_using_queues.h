#include <deque>
#include <iostream>

class Stack {
public:
    Stack() {
        queue1 = new std::deque<int>();
        queue2 = new std::deque<int>();
    }

    ~Stack() {
        delete queue1;
        delete queue2;
    }

    // Push element x onto stack.
    void push(int x) {
        queue2->push_back(x);

        while(!queue1->empty()) {
            int num = queue1->front();
            queue1->pop_front();
            queue2->push_back(num);
        }

        // swap
        std::deque<int>* tmp = queue1;
        queue1 = queue2;
        queue2 = tmp;
    }

    // Removes the element on top of the stack.
    void pop() {
        queue1->pop_front();
    }

    // Get the top element.
    int top() {
        return queue1->front();
    }

    // Return whether the stack is empty.
    bool empty() {
        if(queue1->empty() && queue2->empty())
            return true;
        else
            return false;
    }

    void print_debug() {
        std::deque<int>::iterator it1 = queue1->begin();
        std::deque<int>::iterator it2 = queue2->begin();

        std::cout << "queue 1: ";
        while(it1 != queue1->end()) {
            std::cout << *it1++ << " - ";
        }
        std::cout << std::endl;

        std::cout << "queue 2: ";
        while(it2 != queue2->end()) {
            std::cout << *it2++ << " - ";
        }
        std::cout << std::endl;
    }
private:
    std::deque<int>* queue1;
    std::deque<int>* queue2;
};

