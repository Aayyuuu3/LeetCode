class Solution {
public:
    ListNode *merge_list(ListNode *a, ListNode *b){
        if(!a) return b;
        if(!b) return a;

        ListNode *var = NULL;
        ListNode *head = NULL;
        while(a && b){
            if(a->val <= b->val){
                if(!var){
                    head = a;
                    var = a;
                }
                else{ 
                    var->next = a;
                    var = a;
                }
                a = a->next;
            }
            else{
                if(!var){
                    head = b;
                    var = b;
                }
                else{ 
                    var->next = b;
                    var = b;
                }
                b = b->next;
            }
        }
        var->next = a? a:b;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())
            return NULL;
        ListNode *res = lists[0];
        for(int i=1; i<lists.size(); i++)
            res = merge_list(lists[i],res);
        return res;
    }
};