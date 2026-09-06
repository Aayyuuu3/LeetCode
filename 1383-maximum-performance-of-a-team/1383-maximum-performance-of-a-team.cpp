class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mod = (int)1e9 + 7;
        vector<vector<int>> performance(n,vector<int>(2));
        for(int i = 0; i < n; i++){
            performance[i][0] = speed[i];
            performance[i][1] = efficiency[i];
        }
        sort(performance.begin(),performance.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1] > b[1];
        });
        priority_queue <int, vector<int>, greater<int>> pq;
        long long max_performance = 0;
        long long Total_speed = 0;
        for(int i = 0; i < n; i++){
            if(pq.size() >= k){
                Total_speed -= pq.top();        // eff dont matter because we will any way take
                pq.pop();                   // min(eff) that is per[i][1] so remove lowest speed
            }                               
            Total_speed += performance[i][0];
            pq.push(performance[i][0]);
            long long p = Total_speed * performance[i][1];
            max_performance = max(max_performance,p);          
        }
        return max_performance % mod;
    }
};

// (total_speed) > 0, we sorted in dec eff order as at i index eff_i lowest 
// speed will always inc till k engineers 
// we are calculating max_per at each step as atmost k engineers are needed
// when we reach at k so when we will include next engineer at k + 1 index
// his eff is lowest as it is sorted like that so its better to remove the guy with 
// lowest speed and add engineer k + 1 and check again