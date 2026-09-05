class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int rows = points.size();
        sort(points.begin(),points.end(),[](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        int arrows = 1;
        int prev_end = points[0][1];
        for(int i = 1; i < rows; i ++){
            if(points[i][0] <= prev_end)
                prev_end = min(points[i][1],prev_end);   // prev_end will never be update
             else {                            // no need of if block
                arrows ++;
                prev_end = points[i][1];
            }
        }
        return arrows;
    }
};