class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n);
        prev[0] = grid[0][0];
        for(int i = 1; i < n; i ++)
            prev[i] = grid[0][i] + prev[i-1];
        vector<int> curr(n);
        for(int i = 1; i < m; i ++){
            curr[0] = prev[0] + grid[i][0];
            for(int j = 1; j < n; j ++){
                curr[j] = min(prev[j],curr[j-1]);
                curr[j] += grid[i][j];
            }
            prev = curr;
        }
        return prev[n-1];
    }
};