class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<bool> prev(m+1,false);
        vector<bool> curr(m+1,false);
        prev[0] = true;
        for(int i = 1; i <= m; i ++){
            if(p[i-1] == '*') prev[i] = true;
            else break;
        }
        for(int i = 1; i <= n; i ++){
            curr[0] = false;
            for(int j = 1; j <= m; j ++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    curr[j] = prev[j-1];
                else if(p[j-1] == '*')
                    curr[j] = curr[j-1] || prev[j];             // curr[j-1] = 0 matches
                else curr[j] = false;                          // prev[j] = 1 or more matches
            }
            swap(prev,curr);
        }
        return prev[m];
    }
};