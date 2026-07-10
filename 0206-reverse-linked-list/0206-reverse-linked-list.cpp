class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *prev = head;
        ListNode *curr = head;
        ListNode *next = NULL;
        while(prev){
            curr = prev->next;
            prev->next = next;
            next = prev; 
            prev = curr;
        }
        return next;
    }
};