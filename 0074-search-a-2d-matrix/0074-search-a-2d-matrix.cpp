class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(matrix[mid][0] > target)
                high = mid - 1;
            else if(matrix[mid][n-1] < target)
                low = mid + 1;
            else{
                int row = mid;
                int left = 0;
                int right = n - 1;
                while(left <= right){
                    int mid = left + (right - left) / 2;
                    if(matrix[row][mid] == target)
                        return true;
                    else if(matrix[row][mid] > target)
                        right = mid - 1;
                    else left = mid + 1;
                }
                return false;
            }
        }
        return false;
    }
};