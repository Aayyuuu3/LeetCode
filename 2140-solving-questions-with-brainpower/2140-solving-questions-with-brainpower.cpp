class Solution {
private:
    long long points(vector<vector<int>>& questions, vector<long long>& dp, int idx){
        if(idx >= questions.size()) return 0;

        if(dp[idx] != -1)
            return dp[idx];
        
        long long take = 0;
        long long notTake = 0;    
        
        take = points(questions, dp, idx + questions[idx][1] + 1) + questions[idx][0];
        notTake = points(questions, dp, idx + 1);
        return dp[idx] = max(take, notTake);
        
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return points(questions, dp, 0);
    }
};