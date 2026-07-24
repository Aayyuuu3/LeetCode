class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right){

        if(head->next == NULL || left == right)
            return head;        
        ListNode* dummy = new ListNode(0,head);
        ListNode* prev1 = dummy;

        int k = 0;
        while(k != (left -1)){
            prev1 = prev1->next;
            k++;
        }

        ListNode* node1 = NULL;
        node1 = prev1->next;

        ListNode* node2 = node1;
        k = 0;
        while(k != (right - left)){
            node2 = node2->next;
            k++;
        }

        ListNode* next1 = NULL;
        next1 = node2->next;

        ListNode* prev = NULL;
        ListNode* curr = node1;
        ListNode* next = NULL;
        while(curr != next1){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        prev1->next = node2;
        node1->next = next1;
        return dummy->next;
    }
};