class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();   
        int n = board[0].size();   
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i ++){
            if(board[i][0] == 'O'){
                board[i][0] = '#';
                q.push({i, 0});
            }
            if(board[i][n - 1] == 'O'){
                board[i][n - 1] = '#';
                q.push({i, n - 1});
            }
        }
        for(int i = 0; i < n; i ++){
            if(board[0][i] == 'O'){
                board[0][i] = '#';
                q.push({0, i});
            }
            if(board[m - 1][i] == 'O'){
                board[m - 1][i] = '#';
                q.push({m - 1, i});
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int delrow[4] = {-1, 0, 1, 0};
            int delcol[4] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i ++){
                int r = row + delrow[i];
                int c = col + delcol[i];
                if(r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 'O'){
                    board[r][c] = '#';      
                    q.push({r, c});
                }
            }
        }   
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(board[i][j] == '#')
                    board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};