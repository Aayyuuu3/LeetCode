class Solution {
private:
    bool checkBipartitionBfs(vector<vector<int>>& adj, vector<int>& group, int node){
        queue<int> q;
        q.push(node);
        group[node] = 1;
        while(!q.empty()){    
            int v = q.front();
            q.pop();
            for(auto it: adj[v]){
                if(group[it] == 0){
                    q.push(it);
                    group[it] = 3 - group[v];
                }
                else if(group[it] == group[v]) return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> group(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        for(auto it: dislikes){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1; i <= n; i ++){
            if(group[i] == 0)
                if(!checkBipartitionBfs(adj, group, i)) return false;
        }
        return true;
    }
};