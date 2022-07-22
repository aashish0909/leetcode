/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = new Node(0);
        Node* tempNewHead = newHead;
        Node* tempHead = head;
        while(tempHead) {
            Node* newNode = new Node(tempHead->val);
            tempNewHead->next = newNode;
            tempHead = tempHead->next;
            tempNewHead = tempNewHead->next;
        }
        newHead = newHead->next;
        
        tempNewHead = newHead;
        tempHead = head;
        
        unordered_map<Node*, Node*> mp;
        while(tempHead) {
            mp[tempHead] = tempNewHead;
            tempHead = tempHead->next;
            tempNewHead = tempNewHead->next;
        }
        
        tempNewHead = newHead;
        tempHead = head;
        while(tempHead) {
            tempNewHead->random = mp[tempHead->random];
            tempNewHead = tempNewHead->next;
            tempHead = tempHead->next;
        }
        
        return newHead;
    }
};