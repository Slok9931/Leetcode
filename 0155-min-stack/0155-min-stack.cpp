class MinStack {
    stack<pair<int, int>> s;
    int mini = INT_MAX;
public:
    MinStack() {}
    
    void push(int val) {
        s.push({val, mini});
        mini = min(mini, val);
    }
    
    void pop() {
        auto x = s.top();
        s.pop();
        mini = x.second;
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return mini;
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
