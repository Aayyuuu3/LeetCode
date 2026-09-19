class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        int groups = 1;
        priority_queue<int,vector<int>,greater<int>> end_time;
        end_time.push(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i ++){
            int min_endTime = end_time.top();
            if(min_endTime >= intervals[i][0])
                groups ++;
            else end_time.pop();
            end_time.push(intervals[i][1]);
        }
        return groups;
    }
};