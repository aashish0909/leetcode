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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode* pre = ans;
        
        for(int i = 0; i < left - 1; i++)
            pre = pre->next;
        
        ListNode* start = pre->next;
        ListNode* nNext = start->next;
        
        for(int i = 0; i < right - left; i++) {
            start->next = nNext->next;
            nNext->next = pre->next;
            pre->next = nNext;
            nNext = start->next;
        }
        
        return ans->next;
    }
};