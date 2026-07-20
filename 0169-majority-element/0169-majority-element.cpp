class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_multiset <int> st;
        int k = nums.size() / 2;
        for(auto i: nums){
            st.insert(i);
            if(st.count(i) > k)
                return i;
        }
        return -1;
    }
};