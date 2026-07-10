class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)
            return NULL;
        int k = 0;
        ListNode *temp = head;
        while(temp != NULL){
            temp = temp->next;
            k++;
        }
        int mid = k/2;
        temp = head;
        int j=1;
        while(j <= mid-1){
            temp = temp->next;
            j++;
        }   
        temp->next = temp->next->next;
        return head;
    }
};