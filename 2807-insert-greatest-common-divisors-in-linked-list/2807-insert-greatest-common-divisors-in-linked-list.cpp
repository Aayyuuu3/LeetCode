class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* prev = head;        
        ListNode* curr = head->next;
        while(curr){
            int t = gcd(prev -> val, curr -> val);
            ListNode* temp = new ListNode(t , curr);
            prev -> next = temp;
            prev = curr;
            curr = prev->next;
        }        
        return head;
    }
};