class Solution {
public:
    int num(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }

    bool isPalindrome(ListNode* head) {
        stack <int> st;
        int c = num(head);
        int i=0;
        while(i!=c/2){
            st.push(head->val);
            head=head->next;
            i++;
        }
        if(c%2!=0)
            head = head->next;
        while(head!=NULL){
            if(st.top()!=head->val)
                return false;
            else{
                st.pop();
                head = head->next;
            }
        }
        return true;
    }
};