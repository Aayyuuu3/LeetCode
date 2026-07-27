class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                int cnt = 0;
                if((i - 1) >= 0){
                    if(board[i-1][j] == 1 || board[i-1][j] == 2)
                        cnt++;
                    if((j-1) >= 0 && (board[i-1][j-1] == 1 || board[i-1][j-1] == 2))
                        cnt++; 
                    if((j+1) < board[i].size() && (board[i-1][j+1] == 1 || board[i-1][j+1] == 2))
                        cnt++; 
                }
                if((i + 1) < board.size()){
                    if(board[i+1][j] == 1 || board[i+1][j] == 2)
                        cnt++;
                    if((j-1) >= 0 && (board[i+1][j-1] == 1 || board[i+1][j-1] == 2))
                        cnt++; 
                    if((j+1) < board[i].size() && (board[i+1][j+1] == 1 || board[i+1][j+1] == 2))
                        cnt++; 
                }
                if((j-1) >= 0 && (board[i][j-1] == 1 || board[i][j-1] == 2))
                    cnt++;
                if((j+1) < board[i].size() && (board[i][j+1] == 1 || board[i][j+1] == 2))
                    cnt++;
                if(cnt == 3){
                    if(board[i][j] == 0)
                        board[i][j] = 3;
                }
                else if(cnt > 3 || cnt <2){
                    if(board[i][j] == 1)
                        board[i][j] = 2;
                }
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 3)
                    board[i][j] = 1;
                else if(board[i][j] == 2)
                    board[i][j] = 0;
            }
        }
    }
};