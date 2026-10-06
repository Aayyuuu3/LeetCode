class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<int> prev(n,1);
        vector<int> curr(n,0);
        for(int i = 0; i < n; i ++){
            if(text2[i] != text1[0])
                prev[i] = 0;
            else break;
        }
        for(int i = 1; i < m; i ++){
            curr[0] = (text1[i] == text2[0])? 1:prev[0];
            for(int j = 1; j < n; j ++){
                if(text1[i] == text2[j])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(curr[j-1],prev[j]);
            }
            swap(prev,curr);
        }
        return prev[n-1];
    }
};