class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        vector<vector<int>> visited(m, vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    res[i][j] = 0;
                }
            }
        }
        int level = 0;
        while(!q.empty()){
            level += 1;
            int size = q.size();
            while(size --){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                int delrow[4] = {-1, 0, 1, 0};
                int delcol[4] = {0, 1, 0, -1};
                for(int i = 0; i < 4; i ++){
                    int r = row + delrow[i];
                    int c = col + delcol[i];
                    if(r >= 0 && r < m && c >= 0 && c < n && mat[r][c] == 1 && visited[r][c] == 0){
                        res[r][c] = level;       //  = res[row][col] + 1;
                        q.push({r, c});
                        visited[r][c] = 1;
                    }
                }
            }
        }
        return res;
    }
};