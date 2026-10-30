class Solution {
public:
    bool partition(vector<int>& nums, vector<vector<int>>& dp, int target, int idx){
        if(target == 0) return true;
        if(idx == nums.size()) return false;

        if(dp[idx][target] != -1)
            return dp[idx][target];
        
        bool take = false;
        if(target >= nums[idx]) 
            take = partition(nums, dp, target - nums[idx], idx + 1);
        if(take) return dp[idx][target] = take;
        
        bool notTake = partition(nums, dp, target, idx + 1);
        return dp[idx][target] = notTake; 
    }
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int num: nums) target += num;
        if(target % 2 != 0) return false;
        target /= 2;
        vector<vector<int>> dp(nums.size(), vector<int> (target + 1, -1));
        return partition(nums, dp, target, 0);
    }
};