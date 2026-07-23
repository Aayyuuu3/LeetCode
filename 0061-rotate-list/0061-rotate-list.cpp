class Solution {
public:
    int helper(ListNode *head){
        int n = 0;
        while(head){
            head = head->next;
            n++;
        }
        return n;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = helper(head);
        if(n == 0 || n == 1)
            return head;
        k = k % n;
        if(k == 0)
            return head;
        ListNode *temp = head;
        int i = 0;
        while(i != (n-k-1)){
            temp = temp->next;
            i++;
        }
        ListNode *temp2 = temp->next;
        ListNode *temp3 = head;
        while(temp3->next)
            temp3 = temp3->next;
        temp->next = NULL;
        temp3->next = head;
        return temp2;
    }
};