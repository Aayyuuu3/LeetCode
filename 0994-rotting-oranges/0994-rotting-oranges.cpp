class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();   
        int n = grid[0].size();   
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh += 1;
            }
        }
        if(fresh == 0) return 0;
        int time = -1;
        while(!q.empty()){
            time += 1;
            queue<pair<int,int>> Q;
            while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                grid[r][c] = 0;            
                if(r - 1 >= 0 && grid[r - 1][c] == 1){
                    grid[r - 1][c] = 0;
                    Q.push({r - 1, c});
                    fresh -= 1;
                }
                if(r + 1 < m && grid[r + 1][c] == 1){
                    grid[r + 1][c] = 0;
                    Q.push({r + 1, c});
                    fresh -= 1;
                }
                if(c - 1 >= 0 && grid[r][c - 1] == 1){
                    grid[r][c - 1] = 0;
                    Q.push({r, c - 1});
                    fresh -= 1;
                }
                if(c + 1 < n && grid[r][c + 1] == 1){
                    grid[r][c + 1] = 0;
                    Q.push({r, c + 1});
                    fresh -= 1;
                }
            }
            swap(q,Q);
        }
        if(fresh != 0) return -1;
        return time;
    }
};