class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m+1,0);
        for(int i = 0; i <= m; i ++)
            prev[i] = i;
        vector<int> curr(m+1,0);
        for(int i = 1; i <= n; i ++){
            curr[0] = i; 
            for(int j = 1; j <= m; j ++){
                if(word1[i - 1] == word2[j - 1])
                    curr[j] = prev[j-1];
                else{
                    int c1 = curr[j-1] + 1;        //  insertion
                    int c2 = prev[j-1] + 1;        //  replace
                    int c3 = prev[j] + 1;          //  deletion
                    curr[j] = min({c1, c2, c3});
                }
            }
            swap(prev,curr);
        }
        return prev[m];
    }
};