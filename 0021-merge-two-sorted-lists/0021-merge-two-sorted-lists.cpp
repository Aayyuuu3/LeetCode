class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;       
        if(!list2) return list1;
        ListNode *ans = NULL;       
        ListNode *var = NULL;
        while(list1 && list2) {
            if(list1->val <= list2->val){
                if(!ans){
                    ans = list1;
                    var = list1;
                }
                else{
                    var->next = list1;
                    var = list1;
                }
                list1 = list1->next;
            }
            else{
                if(!ans){
                    ans = list2;
                    var = list2;
                }
                else{
                    var->next = list2;
                    var = list2;
                }
                list2 = list2->next;
            }
        }      
        var->next = (list1)? list1 : list2;
        return ans; 
    }
};