class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set <int> st;
        for(auto candy: candyType)
            st.insert(candy);
        int a = candyType.size() / 2;
        int b = st.size();
        return (a>b)? b : a; 
    }
};