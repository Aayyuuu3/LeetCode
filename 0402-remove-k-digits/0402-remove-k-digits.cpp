class Solution {
public:
    string removeKdigits(string num, int k) {
        // we will start from a smaller digit 
        // and remove k largest digit from the front 
        // for eg 1 4 3 2; k = 2 
        // 12 < 14, 13, 43, 42, 32
        stack <char> st;
        int v = 0;
        for(int i = 0; i < num.size(); i++){
            while(!st.empty() && st.top() > num[i] && v != k){
                st.pop();
                v++;
            }
            st.push(num[i]);
        }
        while(!st.empty() && v != k){
            st.pop();
            v++;
        }
        int size = st.size();
        string ans(size, ' ');
        while(!st.empty()){
            ans[size-1] = st.top();
            size--;
            st.pop();
        }
        int start = 0;
        while(start < ans.size() && ans[start] == '0')
            start++;
        if(start >= ans.size()) 
            return "0"; 
        return ans.substr(start);
    }
};