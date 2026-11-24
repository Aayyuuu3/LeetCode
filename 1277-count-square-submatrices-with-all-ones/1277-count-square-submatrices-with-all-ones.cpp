class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        int sq = 0;
        
        for(int i = 0; i < n; i ++){
            if(matrix[0][i] == 1){
                prev[i] = 1;
                sq += 1;
            }
        }

        for(int i = 1; i < m; i ++){
            curr[0] = 0;
            if(matrix[i][0] == 1){
                curr[0] = 1;
                sq += 1;
            }
            
            for(int j = 1; j < n; j ++){
                if(matrix[i][j] == 1){
                    curr[j] = 1 + min({prev[j], prev[j - 1], curr[j - 1]});
                    sq += curr[j];   
                    // if curr[j] = 3 [it contributes 3 new squares]
                }
                else curr[j] = 0;
            }
            swap(prev, curr);
        }

        return sq;
    }
};