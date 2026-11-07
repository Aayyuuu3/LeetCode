class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});     // {effort, row, col}

        vector<vector<int>> effort(m, vector<int>(n, 1e9));
        effort[0][0] = 0;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while(!pq.empty()){
            int d = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();

            if(d > effort[row][col]) continue;
            if(row == m - 1 && col == n - 1) return d;

            for(int i = 0; i < 4; i ++){
                int nr = row + delRow[i];
                int nc = col + delCol[i];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                    int newEffort = max(d, abs(heights[nr][nc] - heights[row][col]));
                    if(newEffort < effort[nr][nc]){
                        effort[nr][nc] = newEffort;
                        pq.push({newEffort, nr, nc}); 
                    }
                }
            }
        }
        return effort[m - 1][n - 1];
    }
};