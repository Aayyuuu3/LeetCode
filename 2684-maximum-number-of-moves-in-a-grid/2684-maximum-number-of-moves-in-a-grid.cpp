class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int dRow[] = {-1, 0, 1};
        int mxlen = 0;
        
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < m; j ++){
                for(int k = 0; k < 3; k ++){
                    int nr = j + dRow[k];
                    if(nr >= 0 && nr < m && grid[j][i] > grid[nr][i - 1]){
                        if(i != 1 && dp[nr][i - 1] == 0) continue;
                        dp[j][i] = max(dp[j][i], 1 + dp[nr][i - 1]);
                        mxlen = max(mxlen, dp[j][i]);
                    }
                }
            }
        }
        return mxlen;
    }
};