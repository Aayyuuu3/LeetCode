class Solution {
public:
    void reverse(vector <int> &v, int a, int b){
        while(a<b){
            swap(v[a],v[b]);
            a++;
            b--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k = k % (m*n);
        if(k == 0)
            return grid;
        vector <int> helper;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
                helper.push_back(grid[i][j]);
        }
        int s = helper.size();
        reverse(helper,0,s-1);
        reverse(helper,0,k-1);
        reverse(helper,k,s-1);
        int p = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
                grid[i][j] = helper[p++];
        }
        return grid;
    }
};