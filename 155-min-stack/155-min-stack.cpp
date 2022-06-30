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
        if (!head)
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