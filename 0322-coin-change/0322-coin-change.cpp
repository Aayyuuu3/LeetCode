class Solution {
private:
    int minCoins(vector<int>& coins, vector<vector<int>>& dp, int amount, int idx){
        if(amount == 0) return 0;
        if(idx == coins.size()) return INT_MAX;

        if(dp[idx][amount] != -1) return dp[idx][amount];
        
        int take = INT_MAX;
        if(amount >= coins[idx])
            take = minCoins(coins, dp, amount - coins[idx], idx); 
        if(take != INT_MAX) take += 1; 
        
        int notTake = minCoins(coins, dp, amount, idx + 1);
        return dp[idx][amount] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        int coinsNeeded = minCoins(coins, dp, amount, 0);
        return (coinsNeeded != INT_MAX)? coinsNeeded:-1;
    }
};