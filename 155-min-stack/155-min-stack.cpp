class MinStack {
public:
    stack<long long> minStack;
    long long minEle;
    MinStack() {
        
    }
    
    void push(int val) {
        if(minStack.empty())
            minEle = val;
        if(minEle < val) {
            minStack.push(val);
        }
        else {
            minStack.push(0ll + val + val - minEle);
            minEle = val;
        }
    }
    
    void pop() {
        long long x = minStack.top();
        minStack.pop();
        if(x < minEle)
            minEle = minEle + minEle - x;
    }
    
    int top() {
        long long x = minStack.top();
        if(x < minEle)
            return minEle;
        else return x;
    }
    
    int getMin() {
        return minEle;
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