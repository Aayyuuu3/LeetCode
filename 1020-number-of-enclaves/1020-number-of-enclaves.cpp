class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n,0));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i ++){
            if(grid[i][0] == 1){
                q.push({i, 0});
                visited[i][0] = 1;
            }
            if(grid[i][n - 1] == 1){
                q.push({i, n - 1});
                visited[i][n - 1] = 1;
            }
        }
        for(int i = 0; i < n; i ++){
            if(grid[0][i] == 1){
                q.push({0, i});
                visited[0][i] = 1;
            }
            if(grid[m - 1][i] == 1){
                q.push({m - 1, i});
                visited[m - 1][i] = 1;
            }
        }
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i ++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1 && visited[nr][nc] == 0){
                    q.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++)
                if(grid[i][j] == 1 && visited[i][j] == 0) cnt ++;
        }
        return cnt;
    }
};