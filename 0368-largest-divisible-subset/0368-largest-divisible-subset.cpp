class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<pair<int, int>> dp(nums.size(), {1, -1});
        pair<int, int> mxlen = {1, 0};
        
        for(int i = 1; i < nums.size(); i ++){
            for(int j = 0; j < i; j ++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i].first < 1 + dp[j].first){
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = j;
                    } 
                }
            }
            if(mxlen.first < dp[i].first){
                mxlen.first = dp[i].first;
                mxlen.second = i;
            }
        }

        vector<int> res;
        res.reserve(mxlen.first);
        
        int element = mxlen.second;
        while(element != -1){
            res.push_back(nums[element]);
            element = dp[element].second;
        }
        
        return res;
    }
};