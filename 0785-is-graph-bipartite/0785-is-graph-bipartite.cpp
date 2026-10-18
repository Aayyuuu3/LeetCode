class Solution {
private:
    bool checkBipartiteBFS(vector<vector<int>>& graph, vector<int>& visited, int node, int colour){
        queue <int> q;
        q.push(node);
        visited[node] = colour;
        while(!q.empty()){
            if(colour == 1) colour = 2;
            else colour = 1;
            int size = q.size();
            while(size --){
                int n = q.front();
                q.pop();
                for(auto it: graph[n]){
                    if(visited[it] == 0){
                        q.push(it);
                        visited[it] = colour;
                    }
                    else{
                        if(visited[it] != colour)
                            return false;
                    }
                }
            }
        }  
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // every edge of graph can be shown by connection of 2 nodes
        // a node of set A and a node of set B 
        // so two adjacent nodes cannot be in a set for eg in eg1 
        // if A = {0, 1} B = {2, 3} the edge between 0 - 1 is not there between 
        // any node of A and any node of B
        // similar conecpt: no two adj nodes can have same colour
        // implies no 2 adj nodes can be in same set, 1 has to be in A and other in B
        // set A or colour 1
        // set B or colour 2

        int n = graph.size();
        vector<int> visited(n,0);
        int colour = 1;
        for(int i = 0; i < n; i ++){
            if(visited[i] == 0)
                if(!checkBipartiteBFS(graph, visited, i, colour)) return false;
        }
        return true;
    }
};