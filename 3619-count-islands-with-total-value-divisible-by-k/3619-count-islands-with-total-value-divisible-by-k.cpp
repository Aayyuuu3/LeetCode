class Solution {
private:
    int bfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis, int k){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 1;
        long long val = 0;
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            val += grid[row][col];
            for(int i = 0; i < 4; i ++){
                int nr = row + delRow[i];
                int nc = col + delCol[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
                grid[nr][nc] != 0 && vis[nr][nc] == 0){
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        return (val % k == 0)? 1:0;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int islands = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(grid[i][j] != 0 && vis[i][j] == 0)
                    islands += bfs(i, j, grid, vis, k);
            }
        }
        return islands;
    }
};