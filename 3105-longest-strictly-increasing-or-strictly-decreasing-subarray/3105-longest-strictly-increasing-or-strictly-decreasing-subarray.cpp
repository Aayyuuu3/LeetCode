class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mxInc = 1;
        int mxDec = 1;
        int Inc = 1;
        int Dec = 1;

        for(int i = 1; i < nums.size(); i ++){
            if(nums[i] > nums[i - 1]){
                Inc += 1;
                mxInc = max(mxInc, Inc);
            }
            else Inc = 1;
            
            if(nums[i] < nums[i - 1]){
                Dec += 1;
                mxDec = max(mxDec, Dec);
            }
            else Dec = 1;
        }

        return max(mxInc, mxDec);
    }
};