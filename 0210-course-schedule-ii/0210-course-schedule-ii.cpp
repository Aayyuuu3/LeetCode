class Solution {
private:
    bool dfs_hasCycle(vector<vector<int>>& adj, vector<int>& vis, stack<int>& s, int node){
        vis[node] = 1;
        for(int i: adj[node]){
            if(vis[i] == 0){
                if(dfs_hasCycle(adj, vis, s, i)) 
                    return true;
            }
            else if(vis[i] == 1) return true;
        }
        vis[node] = 2;
        s.push(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        stack <int> s;
        for(int i = 0; i < n; i ++){
            if(vis[i] == 0)
                if(dfs_hasCycle(adj, vis, s, i)) return {};
        }
        vector<int> res;
        res.reserve(s.size());
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};