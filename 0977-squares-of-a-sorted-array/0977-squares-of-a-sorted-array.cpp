class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector <int> ans(nums.size());
        int l = 0;
        int r = nums.size()-1;
        int j = 0;
        while(l <= r){
            if(abs(nums[l]) >= abs(nums[r])){
                ans[nums.size()-j-1] = nums[l]*nums[l];
                l++;
            }
            else{
                ans[nums.size()-j-1] = nums[r]*nums[r];
                r--;
            }
            j++;
        }
        return ans;
    }
};