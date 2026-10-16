class Solution {
private:
    void bfs(int i, vector<vector<int>>& adj, vector<int>& vis){
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(vis[it] == 0){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
            return -1;
        vector<vector<int>> adj(n);
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res = -1;
        vector<int> vis(n,0);
        for(int i = 0; i < n; i ++){
            if(vis[i] == 0){
                res += 1;
                bfs(i, adj, vis);
            }
        }
        return res;
    }
};