class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int zeroes = 0;
        int max_length = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == 0)
                zeroes += 1;
            if(zeroes >= 2){
                if(nums[l] == 0)
                    zeroes --;
                l ++;
            }
            max_length = max(max_length, r - l + 1 - zeroes);
        }
        if(max_length == nums.size())
            max_length --;
        return max_length;
    }
};