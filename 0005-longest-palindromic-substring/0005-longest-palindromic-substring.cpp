class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string rev = s; 
        reverse(rev.begin(), rev.end());
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        int mxlen = 0;
        int idx = -1;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(s[i - 1] == rev[j - 1])
                    curr[j] = prev[j - 1] + 1;
                else curr[j] = 0;
                if(curr[j] > mxlen && i - curr[j] == n - j){
                    mxlen = curr[j];
                    idx = i;
                }
            }
            swap(prev, curr);
        }
        string res(mxlen, '\0');
        int len = mxlen - 1;
        while(len >= 0){
            res[len] = s[idx - 1];
            len -= 1;
            idx -= 1;
        }
        return res;
    }
};