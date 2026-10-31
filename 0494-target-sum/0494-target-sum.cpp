class Solution {
private:
    int ways(vector<int>& nums, vector<vector<int>>& dp, int idx, int k){
        if(idx == nums.size()) return (k == 0);

        if(dp[idx][k] != -1) return dp[idx][k];
        
        int take = 0;
        if(k >= nums[idx])
            take = ways(nums, dp, idx + 1, k - nums[idx]);
        int notTake = ways(nums, dp, idx + 1, k);
        return dp[idx][k] = take + notTake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // + to S1, - to S2
        // S1 + S2 = sum    +S1 - S2 = target
        // S1 = (sum + target) / 2;
        int sum = 0;
        for(int num: nums) sum += num;
        if(abs(target) > sum || (sum + target) % 2 != 0) return 0;
        int k = (sum + target) / 2;
        vector<vector<int>> dp(nums.size(), vector<int> (k + 1, -1));
        return ways(nums, dp, 0, k);
    }
};

// abs(target) > sum
// because from nums=> [-sum, sum] so if target should belong in the range