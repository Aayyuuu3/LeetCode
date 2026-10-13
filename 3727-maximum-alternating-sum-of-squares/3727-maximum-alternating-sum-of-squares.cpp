class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](const int& a, const int& b){
            return abs(a) > abs(b);
        });
        
        int n = nums.size();
        int half = (n + 1) / 2;
        long long score = 0;
        
        for(int i = 0; i < n; i ++){
            if(i < half)
                score += 1LL * nums[i] * nums[i];
            else score -= 1LL * nums[i] * nums[i];
        }
        return score;
    }
};