class Solution {
private:
    void dfs(vector<vector<int>>& image, int start, int color, int sr, int sc){
        int m = image.size();    
        int n = image[0].size();
        image[sr][sc] = color;
        if(sr - 1 >= 0){
            if(image[sr - 1][sc] == start)
                dfs(image, start, color, sr - 1, sc);
        }
        if(sr + 1 < m){
            if(image[sr + 1][sc] == start)
                dfs(image, start, color, sr + 1, sc);
        }
        if(sc - 1 >= 0){
            if(image[sr][sc - 1] == start)
                dfs(image, start, color, sr, sc - 1);
        }
        if(sc + 1 < n){
            if(image[sr][sc + 1] == start)
                dfs(image, start, color, sr, sc + 1);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start = image[sr][sc];
        if(start == color) return image;    
        dfs(image, start, color, sr, sc);
        return image;
    }
};