class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *temp = head;
        int k = 0;
        while(temp){
            temp = temp->next;
            k++;
        }       
        temp = head;
        int mid = k/2 + 1;
        int j=1;
        while(j!=mid){
            temp = temp->next;
            j++;
        } 
        return temp;
    }
};