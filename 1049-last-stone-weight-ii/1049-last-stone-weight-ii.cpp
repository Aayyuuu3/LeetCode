class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int stone: stones) sum += stone;
        int k = sum / 2;
        vector<vector<int>> dp(n, vector<int> (k + 1, false));
        for(int i = 0; i < n; i ++)
            dp[i][0] = true;
        if(stones[0] <= k) dp[0][stones[0]] = true;
        for(int i = 1; i < n; i ++){
            for(int j = 1; j <= k; j ++){
                bool take = false;
                if(j >= stones[i])
                    take = dp[i - 1][j - stones[i]];
                bool notTake = dp[i - 1][j];
                dp[i][j] = take || notTake;
            }
        }
        int sum1 = 0;
        for(int i = k; i >= 0; i --){
            if(dp[n - 1][i]){
                sum1 = i;
                break;
            }
        }
        int sum2 = sum - sum1;
        return abs(sum2 - sum1);
    }
};