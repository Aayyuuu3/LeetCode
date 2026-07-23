class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp1 = list1;
        ListNode *temp2 = list1;
        ListNode *temp3 = list2;
        while(temp3->next != NULL)
            temp3 = temp3->next;
        int k = 1;
        while(k != a){
            temp1 = temp1->next;
            k++;
        }
        k = 0;
        while(k != (b+1)){
            temp2 = temp2->next;
            k++;
        }
        temp1->next = list2;
        temp3->next = temp2;
        return list1;
    }
};