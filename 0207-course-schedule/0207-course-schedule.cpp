class Solution {
private:
    bool dfs_hasCycle(vector<vector<int>>& adj, vector<int>& vis, int node){
        vis[node] = 1;
        for(int i: adj[node]){
            if(vis[i] == 0){
                if(dfs_hasCycle(adj, vis, i)) 
                    return true;
            }
            else if(vis[i] == 1) return true;
        }
        vis[node] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        vector<int> vis(n,0);
        for(int i = 0; i < n; i ++){
            if(vis[i] == 0)
                if(dfs_hasCycle(adj, vis, i)) return false;
        }
        return true;
    }
};