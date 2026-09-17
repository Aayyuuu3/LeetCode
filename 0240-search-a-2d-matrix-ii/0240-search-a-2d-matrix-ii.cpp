class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int r = 0;
        int c = n - 1;
        while(r >= 0 && r < m){
            if(matrix[r][c] == target)
                return true;
            else if(matrix[r][c] < target)
                r ++;
            else{
                if(c > 0) c--;
                else return false;
            } 
        }
        return false;
    }
};