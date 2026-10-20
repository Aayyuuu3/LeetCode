class Solution {
private:
    void path(vector<vector<int>>& grid, vector<vector<int>>& steps){
        int n = grid.size();
        queue<pair<int,int>> q;
        q.push({0, 0});
        steps[0][0] = 1;
        int delRow[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delCol[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 8; i ++){
                int row = r + delRow[i];
                int col = c + delCol[i];
                if(row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0 
                && steps[row][col] == 0){
                    q.push({row, col});
                    steps[row][col] = steps[r][c] + 1;
                }
            }
        }
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1]) return -1;
        vector<vector<int>> steps(n, vector<int>(n,0));
        path(grid, steps);
        return (steps[n-1][n-1] != 0)? steps[n-1][n-1]:-1;
    }
};