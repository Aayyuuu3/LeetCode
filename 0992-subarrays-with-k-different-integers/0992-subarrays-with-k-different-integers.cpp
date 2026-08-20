class Solution {
public:
    int subarrays(vector<int>& nums,int k){
        if(k == 0)
            return 0;
        vector<int> map(nums.size() + 1, 0);
        int l = 0;
        int r = 0;
        int count = 0;
        int ans = 0;
        while(r < nums.size()){
            map[nums[r]] ++;
            if(map[nums[r]] == 1)
                count ++;
            while(count > k){
                map[nums[l]] --;
                if(map[nums[l]] == 0)
                    count --;
                l ++;
            }
            ans += r - l + 1;
            r ++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrays(nums,k) - subarrays(nums,k-1);
    }
};