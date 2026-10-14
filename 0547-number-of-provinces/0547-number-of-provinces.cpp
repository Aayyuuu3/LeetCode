class Solution {
private:
    void bfs(vector<vector<int>>& isConnected, vector<int>& visited, int i){        
        int n = isConnected.size();
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i = 1; i <= n; i ++){
                if(isConnected[node - 1][i-1] == 1 && visited[i] == 0){
                    q.push(i);
                    visited[i] = 1; 
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); 
        int provinces = 0;
        
        vector<int> visited(n+1,0);

        for(int i = 1; i <= n; i ++){
            if(visited[i] == 0){
                provinces += 1;
                bfs(isConnected, visited, i);
            }
        }

        return provinces;
    }
};