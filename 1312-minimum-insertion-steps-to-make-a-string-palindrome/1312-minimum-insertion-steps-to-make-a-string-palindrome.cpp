class Solution {
public:
    int lcs_len(string& s, string& s1, vector<vector<int>>& dp){
        int n = s.size();
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(s[i-1] == s1[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }

    int minInsertions(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s1.begin(),s1.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        return n - lcs_len(s,s1,dp);
    }
};