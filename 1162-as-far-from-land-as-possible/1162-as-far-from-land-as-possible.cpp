class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                if(grid[i][j] == 1){
                    dp[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i ++){
                int nr = row + delRow[i];
                int nc = col + delCol[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && dp[nr][nc] == -1){
                        dp[nr][nc] = dp[row][col] + 1;
                        q.push({nr, nc});
                }
            }
        }
        int mxlen = 0;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++)
                mxlen = max(mxlen, dp[i][j]);
        }
        return (mxlen == 0)? -1:mxlen;
    }
};