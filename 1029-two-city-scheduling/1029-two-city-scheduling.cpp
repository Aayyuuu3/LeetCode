class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](const vector<int>& a, const vector<int>& b){
            return abs(a[0] - a[1]) > abs(b[0] - b[1]);
        });
        int n = costs.size();
        int limit = n / 2;
        int n1 = 0;
        int n2 = 0;
        int cost = 0;
        for(int i = 0; i < n; i++){
            if(costs[i][0] < costs[i][1]){
                if(n1 < limit){
                    cost += costs[i][0];
                    n1 ++;
                }
                else{
                    cost += costs[i][1];
                    n2 ++;
                }
            }
            else{
                if(n2 < limit){
                    cost += costs[i][1];
                    n2 ++;
                }
                else{
                    cost += costs[i][0];
                    n1 ++;
                }
            }
        }
        return cost;
    }
};