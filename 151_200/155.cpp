//
// Created by janeuler on 2024/8/30.
//

# include <stack>

class MinStack {
    std::stack<int> dataStack;
    std::stack<int> minStack;

public:
    MinStack() {
    }

    void push(int val) {
        dataStack.push(val);
        if (minStack.empty() || getMin() >= val) {
            minStack.push(val);
        }
    }

    void pop() {
        if (dataStack.top() == minStack.top()) {
            minStack.pop();
        }
        dataStack.pop();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
