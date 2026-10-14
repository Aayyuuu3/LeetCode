class Solution {
private: 
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited){
        int m = grid.size();
        int n = grid[0].size();
        visited[row][col] = 1;
        if(row - 1 >= 0){
            if(grid[row - 1][col] == '1' && visited[row - 1][col] == 0)
                dfs(row - 1, col, grid, visited);
        }
        if(row + 1 < m){
            if(grid[row + 1][col] == '1' && visited[row + 1][col] == 0)
                dfs(row + 1, col, grid, visited);
        }
        if(col - 1 >= 0){
            if(grid[row][col - 1] == '1' && visited[row][col - 1] == 0)
                dfs(row, col - 1, grid, visited);
        }
        if(col + 1 < n){
            if(grid[row][col + 1] == '1' && visited[row][col + 1] == 0)
                dfs(row, col + 1, grid, visited);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        int islands = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(visited[i][j] == 0 && grid[i][j] == '1'){
                    islands += 1;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return islands;
    }
};