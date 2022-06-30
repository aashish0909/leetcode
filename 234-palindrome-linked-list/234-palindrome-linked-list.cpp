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
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast;
        slow = fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* temp = reverse(slow->next);
        
        fast = head;
        while(temp) {
            if(fast->val != temp->val) return false;
            fast = fast->next;
            temp = temp->next;
        }
        
        return true;        
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while(head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
};