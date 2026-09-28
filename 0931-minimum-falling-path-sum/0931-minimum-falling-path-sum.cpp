class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev = matrix[0];
        vector<int> curr(n);
        for(int i = 1; i < n; i ++){
            curr[0] = min(prev[0],prev[1]) + matrix[i][0];
            for(int j = 1; j < n-1; j ++){
                int choice1 = prev[j-1] + matrix[i][j]; 
                int choice2 = prev[j] + matrix[i][j]; 
                int choice3 = prev[j+1] + matrix[i][j]; 
                curr[j] = min({choice1,choice2,choice3});
            }
            curr[n-1] = min(prev[n-2],prev[n-1]) + matrix[i][n-1];
            prev = curr;
        }
        return *min_element(prev.begin(),prev.end());
    }
};