class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int m = *max_element(days.begin(),days.end());
        int i = 0;
        vector<int> dp(m+1);
        dp[0] = 0;
        for(int j = 1; j <= m; j ++){
            if(days[i] == j){
                int c1 = dp[j-1] + costs[0];
                int c2 = dp[0] + costs[1];
                if(j - 7 >= 0)
                   c2 =  dp[j-7] + costs[1];
                int c3 = dp[0] + costs[2]; 
                if(j - 30 >= 0)
                    c3 = dp[j-30] + costs[2];
                dp[j] = min({c1,c2,c3});
                i ++;
            }
            else dp[j] = dp[j-1];
        }
        return dp[m];
    }
};