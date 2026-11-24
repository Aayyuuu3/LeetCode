class Solution {
private:
    bool check(string& s, string& t){
        int i = 0;
        int j = 0;
        int m = s.size();
        int n = t.size();
        while(i < m && j < n){
            if(s[i] == t[j])
                i ++;
            j ++;
        }
        return i == m;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });

        int n = words.size();
        vector<int> dp(n, 1);
        int mxlen = 1;
        
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < i; j ++){
                if(words[i].size() - 1 == words[j].size()){
                    if(check(words[j], words[i]))
                        dp[i] = max(dp[i], dp[j] + 1); 
                }
            }
            mxlen = max(mxlen, dp[i]);
        }
        return mxlen;
    }
};