/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* temp = head;
        
        while(l1 && l2) {
            int curr = l1->val + l2->val + carry;
            temp->next = new ListNode(curr % 10);
            carry = curr / 10;
            
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }
        
        head = head->next;
        
        while(l1) {
            int curr = l1->val + carry;
            temp->next = new ListNode(curr % 10);
            carry = curr / 10;
            
            temp = temp->next;
            l1 = l1->next;
        }
        
        while(l2) {
            int curr = l2->val + carry;
            temp->next = new ListNode(curr % 10);
            carry = curr / 10;
            
            temp = temp->next;
            l2 = l2->next;
        }
        
        if(carry)
            temp->next = new ListNode(carry);
        
        return head;
    }
};