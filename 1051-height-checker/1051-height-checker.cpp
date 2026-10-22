class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> count(101,0);
        for(int height: heights)
            count[height] ++;
        int n = heights.size();
        int cnt = 0;
        int k = 0;
        for(int height: heights){
            while(count[k] == 0)
                k ++;
            if(height != k)
                cnt ++;
            count[k] --;
        }   
        return cnt;
    }
};