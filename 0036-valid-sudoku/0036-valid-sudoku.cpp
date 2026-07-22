class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                int boxIdx = (i / 3) * 3 + (j / 3);
                if(board[i][j] == '.')
                    continue;
                int val = board[i][j] - '0';
                if(row[i][val-1] || col[j][val-1]
                        || box[boxIdx][val-1])
                    return false;
                row[i][val-1] = true;
                col[j][val-1] = true;
                box[boxIdx][val-1] = true;
            }
        }
        return true;
    }
};