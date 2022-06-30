class MinStack {
private:
    class Node {
    public:
        int val;
        int min;
        Node* next;
        
        Node(int v, int x, Node* next) {
            this->val = v;
            this->min = x;
            this->next = next;
        }
    };
    
    Node* head;
    
public:
    
    MinStack() {
        head = NULL;
    }
    
    void push(int val) {
        if(!head)
            head = new Node(val, val, head);
        else 
            head = new Node(val, min(head->min, val), head);
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
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