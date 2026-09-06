class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();
        while(i < n && intervals[i][0] < newInterval[0])
            ans.push_back(intervals[i++]);
        if(!ans.empty() && ans.back()[1] >= newInterval[0])
            ans.back()[1] = max(ans.back()[1],newInterval[1]);
        else 
            ans.push_back(newInterval);
        while(i < n && ans.back()[1] >= intervals[i][0]){
            ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            i++;
        }
        while(i < n)
            ans.push_back(intervals[i++]);
        return ans;
    }
};