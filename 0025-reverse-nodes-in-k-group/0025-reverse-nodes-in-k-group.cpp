    class Solution {
    public:
        int nodes(ListNode *head){
            int i = 0;
            while(head != NULL){
                i++;
                head = head->next;;
            }
            return i;
        }
        ListNode* reverseKGroup(ListNode* head, int k) {
            int v = 0;
            int n = nodes(head); 
            ListNode *prev = NULL;
            ListNode *curr = head;
            ListNode *next = NULL;
            ListNode *ans = NULL;
            ListNode *temp = NULL;
            ListNode *temp2 = temp;
            int count = 0;
            while((v + k) <= n){
                int var = 0;  
                temp2 = temp;
                temp = curr;
                while(var != k){
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;    
                    var++;
                }   
                count++;
                if(count == 1)
                    ans = prev;
                temp->next = curr;
                if(temp2)
                    temp2->next = prev;
                prev = NULL;
                v += k;
            }
            return ans;
        }
    };