class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0;
        int i = 0;
        int n = stations.size();
        priority_queue <int> pq;
        while(startFuel < target){
            while(i < n && startFuel >= stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty())
                return -1;
            startFuel += pq.top();
            pq.pop();
            stops += 1;
        }
        return stops;
    }
};