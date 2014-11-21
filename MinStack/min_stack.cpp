#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>

using namespace std;

class MinStack {
public:
    void push(int x) {
        int_stack.push(x);

        if (min_stack.empty() 
            || int_stack.top() <= min_stack.top())
        {
            min_stack.push(x);
        }
    }

    void pop() {
        if (int_stack.empty())
        {
            return;
        }

        if (int_stack.top() == min_stack.top())
        {
            min_stack.pop();
        }

        int_stack.pop();
    }

    int top() {
        if (!int_stack.empty())
        {
            return int_stack.top();
        }

        return -1;
    }

    int getMin() {
        if (!min_stack.empty())
        {
            return min_stack.top();
        }

        return -1;
    }

private:
    stack<int> int_stack;
    stack<int> min_stack;
};

int main(int argc, char **argv)
{
    int f;
    cin >> f;
}