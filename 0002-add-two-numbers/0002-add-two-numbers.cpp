class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        while(l1 != NULL || l2 != NULL || carry != 0){
            int sum = carry;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            ListNode *temp2 = new ListNode(sum % 10);
            temp->next = temp2;
            temp = temp2;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            carry = sum/10;  // updating carry for next iteration
        }
        return dummy->next;
    }
};