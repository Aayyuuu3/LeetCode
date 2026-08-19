class Solution {
public:
    int NiceSubarrays(vector<int>& nums, int k){
        int l = 0;
        int r = 0;
        int count = 0;
        int NiceSubarrays_ = 0;
        while(r < nums.size()){
            if(nums[r] % 2 != 0)
                count ++;
            while(count > k){
                if(nums[l] % 2 != 0)
                    count --;
                l ++;
            }
            NiceSubarrays_ += r - l + 1;
            r ++;
        }
        return NiceSubarrays_;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (NiceSubarrays(nums,k) - NiceSubarrays(nums,k-1));
    }
};