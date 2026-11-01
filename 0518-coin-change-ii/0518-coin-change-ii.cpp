class Solution {
private:
    int ways(vector<int>& coins, vector<vector<int>>& dp, int idx, int amount){
        if(amount == 0) return 1;
        if(idx == coins.size()) return 0;

        if(dp[idx][amount] != -1)
            return dp[idx][amount];
        
        int take = 0;
        if(amount >= coins[idx])
            take = ways(coins, dp, idx, amount - coins[idx]);

        int notTake = ways(coins, dp, idx + 1, amount);
        return dp[idx][amount] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        return ways(coins, dp, 0, amount);
    }
};