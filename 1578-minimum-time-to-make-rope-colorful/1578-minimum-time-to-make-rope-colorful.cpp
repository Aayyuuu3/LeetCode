class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int min_time = 0;
        for(int i = 0; i < n - 1; i++){
            if(colors[i] == colors[i + 1]){
                if(neededTime[i + 1] < neededTime[i]){
                    min_time += neededTime[i + 1];
                    neededTime[i + 1] = neededTime[i];
                }
                else min_time += neededTime[i];
            }
        }
        return min_time;
    }
};