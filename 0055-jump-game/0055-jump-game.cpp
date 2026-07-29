class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        if(n == 0)
            return true;
        int maxIdx = 0;
        for(int i = 0; i < n ; i ++){
            if(i >= maxIdx && nums[i] == 0)
                return false;
            maxIdx = max(maxIdx,i + nums[i]);
            if(maxIdx >= n)
                return true;
        } 
        return false;
    }
};