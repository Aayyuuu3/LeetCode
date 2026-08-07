class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector <int> pse(n);  // -1 if doesn't exist
        vector <int> nse(n);  // n if doesn't exist
        stack <int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
            if(st.empty()){
                pse[i] = -1;
                st.push(i);
            }
            else{
                pse[i] = st.top();
                st.push(i);
            }   
        }
        while(!st.empty())
            st.pop();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
            if(st.empty()){
                nse[i] = n;
                st.push(i);
            }
            else{
                nse[i] = st.top();
                st.push(i);
            }   
        }
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int currArea = heights[i] * (nse[i] - pse[i] -1);
            maxArea = max(maxArea , currArea);
        }
        return maxArea;
    }
};