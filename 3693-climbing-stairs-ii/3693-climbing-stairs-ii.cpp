class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n == 1) return costs[0] + 1;

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = costs[0] + 1;
        dp[2] = min(dp[1] + costs[1] + 1, costs[1] + 4);
        
        for(int i = 3; i <= n; i ++){
            int a = costs[i-1] + dp[i-3] + 9;
            int b = costs[i-1] + dp[i-2] + 4;
            int c = costs[i-1] + dp[i-1] + 1;
            dp[i] = min({a,b,c});
        }
        return dp[n];
    }
};