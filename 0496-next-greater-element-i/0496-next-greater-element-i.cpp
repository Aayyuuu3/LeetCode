class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack <int> st;
        vector <int> ans(nums1.size(),-1);
        st.push(nums2[nums2.size()-1]);
        int temp[10001] = {0};
        temp[nums2[nums2.size()-1]] = -1;
        for(int i = nums2.size()-2 ; i >= 0; i--){
            while(!st.empty() && st.top() < nums2[i])
                st.pop();
            if(st.empty())
                temp [nums2[i]] = -1;
            else
                temp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); i++)
            ans[i] = temp[nums1[i]];
        return ans;
    }
};