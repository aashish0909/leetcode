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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 1) return head;
        ListNode* ans = new ListNode(-1);
        ans->next = head;
        ListNode* start = ans;
        for(int i = 1; head != NULL; i++) { 
            ListNode* next = head->next;
            if(i % k == 0)
                start = reverse(start, next);
            head = next;
        }
        
        return ans->next;
    }
    
    ListNode* reverse(ListNode* head_prev, ListNode* end) {
        ListNode* cur = head_prev->next;
        ListNode* new_head_prev = cur;
        ListNode* prev = head_prev;
        ListNode* next;

        while(cur != end){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        head_prev->next = prev;
        new_head_prev->next = cur;
        
        return new_head_prev;
    }
};