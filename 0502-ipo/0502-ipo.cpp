class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects(n);
        for(int i = 0; i < n; i ++){
            projects[i].first = capital[i];
            projects[i].second = profits[i];
        }
        sort(projects.begin(),projects.end(),[](const pair<int,int>& a, const pair<int,int>& b){
            return a.first < b.first;
        });
        priority_queue <int> pq;
        int steps = 0;
        int i = 0;
        for(int steps = 0; steps < k; steps ++){
            while(i < n && projects[i].first <= w){
                pq.push(projects[i].second);
                i ++;
            }
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};