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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        
        int len = lists.size();
        while(len > 1) {
            for(int i = 0; i < len / 2; i++)
                lists[i] = mergeTwoLists(lists[i], lists[len - i - 1]);
            len = (len + 1) / 2;
        }
        
        return lists.front();
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;
        
        while(l1 && l2) {
            ListNode* newNode = new ListNode();
            if(l1->val < l2->val)
                newNode->val = l1->val, l1 = l1->next;
            else
                newNode->val = l2->val, l2 = l2->next;
            
            temp->next = newNode;
            temp = temp->next;
        }
        
        while(l1) {
            temp->next = new ListNode(l1->val);
            temp = temp->next;
            l1 = l1->next;
        }
        
        while(l2) {
            temp->next = new ListNode(l2->val);
            temp = temp->next;
            l2 = l2->next;
        }
        
        return head->next;
    }
};