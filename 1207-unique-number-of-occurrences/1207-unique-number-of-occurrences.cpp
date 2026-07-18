class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int hash[2001] = {0};
        for(auto a: arr)
            hash[a + 1000]++;
        int ele = 0;
        unordered_set<int> st;
        for(auto h: hash){
            if(h){
                ele++;
                st.insert(h);
            }
        }
        return (st.size() == ele);
    }
};