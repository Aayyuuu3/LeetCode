class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int num: nums)
            st.insert(num);
        int len = 0;
        for(int num: st){
            if(st.find(num - 1) != st.end())
                continue;
            int cnt = 1;
            int n = num + 1;
            while(st.find(n) != st.end()){
                cnt += 1;
                n += 1;
            }
            len = max(len, cnt);
        }
        return len;
    }
};