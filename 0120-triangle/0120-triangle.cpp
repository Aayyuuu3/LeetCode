class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n);
        prev[0] = {triangle[0][0]};
        vector<int>curr(n);
        for(int i = 1; i < n; i ++){
            int m = triangle[i].size();
            curr[0] = prev[0] + triangle[i][0];
            for(int j = 1; j < m-1; j ++){
                curr[j] = min(prev[j],prev[j-1]);
                curr[j] += triangle[i][j];
            }
            curr[m-1] = prev[m-2] + triangle[i][m-1];
            swap(prev, curr);
        }
        return *min_element(prev.begin(),prev.end());
    }
};