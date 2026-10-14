#include <stack>
class MyQueue {
private:
    std::stack<int> in_stack;
    std::stack<int> out_stack;
    void transfer() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
    }
public:
    MyQueue() {}
    void push(int x) {
        in_stack.push(x);
    }
    int pop() {
        transfer();
        int front = out_stack.top();
        out_stack.pop();
        return front;
    }
    int peek() {
        transfer();
        return out_stack.top();
    }
    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};