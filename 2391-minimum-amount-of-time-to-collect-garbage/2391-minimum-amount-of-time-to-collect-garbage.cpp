class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time = 0;
        int m = 0;
        int p = 0;
        int g = 0;
        for(int i = 0; i < garbage.size(); i++){
            time += garbage[i].size();
            for(char c : garbage[i]){
                if(c == 'M') m = i;
                if(c == 'P') p = i;
                if(c == 'G') g = i;
            }
        }
        for(int i = 1; i < travel.size(); i++){
            travel[i] += travel[i-1];
        }
        if(m) time += travel[m-1];
        if(p) time += travel[p-1];
        if(g) time += travel[g-1];
        return time;
    }
};