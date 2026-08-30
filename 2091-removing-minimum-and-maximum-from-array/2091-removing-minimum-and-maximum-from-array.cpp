class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = 0;
        int maxIdx = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[maxIdx])
                maxIdx = i;
            if(nums[i] < nums[minIdx])
                minIdx = i;
        }
        int l = 0;
        int r = nums.size() - 1;
        int m1 = max(maxIdx,minIdx);
        l = m1 + 1;
        int m2 = min(maxIdx,minIdx);
        r = r - m2 + 1;
        int ans = min(l,r);
        r = nums.size() - 1;
        int lr = m2 + 1 + r - m1 + 1;
        ans = min(ans,lr);
        return ans;
    }
};