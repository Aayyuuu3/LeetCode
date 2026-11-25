class Solution {
private:
    void dfs(vector<vector<int>>& rooms, vector<int>& visited, int node){
        visited[node] = 1;
        for(auto n: rooms[node]){
            if(visited[n] == 0)
                dfs(rooms, visited, n);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);
        dfs(rooms, visited, 0);
        for(int i = 0; i < n; i ++){
            if(visited[i] == 0) return false;
        }
        return true;
    }
};