class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode * odd = head;        
        ListNode * even = head->next;        
        ListNode * even2 = head->next;
        while(even && even->next){
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }        
        odd->next = even2;
        return head;
    }
};