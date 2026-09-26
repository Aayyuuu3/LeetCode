class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0],nums[1]);
        int prev2 = nums[0];
        int Prev2 = nums[1];
        int prev = max(prev2, nums[1]);
        int Prev = max(Prev2, nums[2]);
        for(int i = 2; i < n - 1; i ++){
            int curr = prev2 + nums[i];
            prev2 = prev;
            prev = max(prev, curr);
            int Curr = Prev2 + nums[i + 1];
            Prev2 = Prev;
            Prev = max(Prev, Curr);
        }
        return max(prev, Prev);
    }
};