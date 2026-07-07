class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        while(l<n && nums[l]!=1)
            l++;
        if(l==n) return 0;
        int max_len = 0;
        for(int i = l; i < n; i++){
            if(nums[i]!=1){
                max_len = max(max_len,i-l);
                l = i+1;
            }
        }
        if(l!=n)
            max_len = max(max_len,n-l);
        return max_len;
    }
};