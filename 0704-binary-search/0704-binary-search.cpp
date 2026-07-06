class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int r=low + ( high - low )/2;
            if(nums[r]==target) return r;
            else if(nums[r]>target)
                high = r-1;
            else low = r+1;
        }
        return -1;
    }
};