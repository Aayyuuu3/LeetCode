class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n,0);
        for(int i = 0; i < n; i ++){
            if(obstacleGrid[0][i] == 0)
                prev[i] = 1;
            else break;
        }
        vector<int> curr(n);
        for(int i = 1; i < m; i ++){
            curr[0] = (obstacleGrid[i][0] == 1)? 0:prev[0];
            for(int j = 1; j < n; j ++){
                if(obstacleGrid[i][j] == 1)
                    curr[j] = 0;
                else curr[j] = curr[j-1] + prev[j];
            }
            prev = curr;
        }
        return prev[n-1];
    }
};