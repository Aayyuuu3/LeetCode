class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // max length of the subarray with atmost k zeroes
        int l = 0;
        int max_length = 0;
        int zeroes = 0;
        for(int r = 0; r < nums.size(); r++){
            while(zeroes == k && nums[r] == 0){
                if(nums[l] == 0)
                    zeroes--;
                l++;
            } 
            if(nums[r] == 0)
                zeroes ++;
            max_length = max(max_length , r - l + 1);
        }
        return max_length;
    }
};