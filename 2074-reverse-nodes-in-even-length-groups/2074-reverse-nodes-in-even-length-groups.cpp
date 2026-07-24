class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(head->next == NULL)
            return head;
        ListNode* prevTail = head;
        ListNode* temp = head->next;
        int prevLength = 1;
        while(temp != NULL){
            int length = 1;
            ListNode* temp2 = temp;
            while(temp2->next && length != prevLength + 1){
                temp2 = temp2->next;
                length += 1;
            }
            if(length % 2 == 0){
                ListNode* prev = NULL;
                ListNode* curr = temp;
                ListNode* next = NULL;
                ListNode* NextGroup = temp2->next;
                while(curr != NextGroup){
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
                prevTail->next = prev;
                prevTail = temp;
                temp->next = curr;
                temp = curr;
                prevLength = length;
            }
            else{
                prevTail = temp2;
                temp = prevTail->next;
                prevLength = length;
            }
        }
        return head;
    }
};