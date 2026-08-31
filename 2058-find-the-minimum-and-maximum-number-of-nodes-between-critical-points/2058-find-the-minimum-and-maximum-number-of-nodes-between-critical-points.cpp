class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == NULL)
            return {-1,-1};
        int prev_critical = -1;
        int first = -1;
        int idx = 1;
        int min_dist = INT_MAX;
        int max_dist = INT_MIN;
        ListNode* curr = head->next;
        int prev_val = head->val;
        while(curr->next != NULL){
            int next_val = curr->next->val;
            idx += 1;
            if(curr->val > prev_val && curr->val > next_val ||
            curr->val < prev_val && curr->val < next_val){
                if(first == -1){
                    first = idx;
                    prev_critical = idx;
                }
                min_dist = min(min_dist , idx - prev_critical);
                if(min_dist == 0)
                    min_dist = INT_MAX;
                max_dist = max(max_dist,idx - first);
                prev_critical = idx;
            }
            prev_val = curr->val;
            curr = curr->next;
        }
        if(min_dist == INT_MAX) min_dist = -1;
        if(max_dist == INT_MIN || max_dist == 0) max_dist = -1;
        return {min_dist,max_dist};
    }
};