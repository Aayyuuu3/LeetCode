class Solution {
private:
    int Profit(vector<int>& prices, vector<vector<int>>& dp, int idx, int canBuy){
        if(idx == prices.size()) return 0;

        if(dp[idx][canBuy] != -1)
            return dp[idx][canBuy];
        
        if(canBuy){
            int pur = Profit(prices, dp, idx + 1, 0) - prices[idx];
            int notPur = Profit(prices, dp, idx + 1, 1);
            dp[idx][canBuy] = max(pur, notPur);
        }
        
        if(!canBuy){
            int sold = Profit(prices, dp, idx + 1, 1) + prices[idx];
            int notSold = Profit(prices, dp, idx + 1, 0);
            dp[idx][canBuy] = max(sold, notSold);
        }

        return dp[idx][canBuy];
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return Profit(prices, dp, 0, 1);
    }
};