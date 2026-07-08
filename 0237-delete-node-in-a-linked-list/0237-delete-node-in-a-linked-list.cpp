class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *temp = node;
        ListNode *temp2 = temp;
        while(temp->next!=NULL){
            temp->val = temp->next->val;
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
    }
};