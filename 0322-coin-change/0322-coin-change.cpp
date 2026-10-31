class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 1e9);
        for(int i = 0; i <= amount; i ++){
            if(i % coins[0] == 0)
                prev[i] = i / coins[0];
        }
        vector<int> curr(amount + 1, 1e9);
        for(int i = 1; i < n; i ++){
            curr[0] = 0;
            for(int j = 1; j <= amount; j ++){
                int take = 1e9;
                if(j >= coins[i])
                    take = 1 + curr[j - coins[i]];
                int notTake = prev[j];
                curr[j] = min(take, notTake);
            }
            swap(prev, curr);
        }
        return (prev[amount] < 1e9)? prev[amount]:-1;
    }
};