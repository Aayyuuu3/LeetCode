class Solution {
private:
    int bfsArea(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int area = 0;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            area += 1;
            for(int i = 0; i < 4; i ++){
                int nr = row + delRow[i];
                int nc = col + delCol[i];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n && vis[nr][nc] == 0 && grid[nr][nc] == 1){
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mxArea = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(vis[i][j] == 0 && grid[i][j] == 1)
                    mxArea = max(mxArea, bfsArea(grid, vis, i, j));
            }
        }
        return mxArea;
    }
};