class Solution {
private:
    void bfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& isVisited, int& islands){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        q.push({r, c});
        isVisited[r][c] = 1;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        int check = 0;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i ++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n && 
                grid[nr][nc] == 0 && isVisited[nr][nc] == 0){
                    q.push({nr, nc});
                    isVisited[nr][nc] = 1;
                }
                else if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                    check = 1;
            }
        }
        if(check) islands -= 1;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> isVisited(m, vector<int>(n,0));
        int islands = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(grid[i][j] == 0 && isVisited[i][j] == 0){
                    bfs(i, j, grid, isVisited, islands);
                    islands += 1;
                }
            }
        }
        return islands;
    }
};