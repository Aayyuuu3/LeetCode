class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num = 0;
        while(head){
            int t = head->val;
            num *= 2;
            num += t;
            head = head->next;
        }        
        return num;
    }
};