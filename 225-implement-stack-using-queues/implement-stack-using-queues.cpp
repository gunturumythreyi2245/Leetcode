#include <queue>
class MyStack {
private:
    std::queue<int> q;
public:
    MyStack() {
        
    }
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for (int i = 0; i < sz - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int topVal = q.front();
        q.pop();
        return topVal;
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};