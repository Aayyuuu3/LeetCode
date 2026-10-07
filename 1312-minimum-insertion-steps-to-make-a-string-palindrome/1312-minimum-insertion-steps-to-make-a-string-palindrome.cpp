class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s1.begin(),s1.end());
        vector<int> prev(n+1);
        vector<int> curr(n+1);
        for(int i = 0; i <= n; i ++)
            prev[i] = i;
        for(int i = 1; i <= n; i ++){
            curr[0] = i;
            for(int j = 1; j <= n; j ++){
                if(s[i-1] == s1[j-1])
                    curr[j] = prev[j-1];
                else
                    curr[j] = min(prev[j],curr[j-1]) + 1;
            }
            swap(prev,curr);
        }
        return prev[n]/2;
    }
};