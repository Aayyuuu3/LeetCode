class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // LCS of a string s and its reverse s1 will be palindrome
        // LCS: common subseq...which is same from front and back so it will be palindrome
        int n = (int)s.size();
        string s1 = s;
        reverse(s1.begin(),s1.end());
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(s[i-1] == s1[j-1])
                    curr[j] = prev[j-1] + 1;
                else curr[j] = max(curr[j-1],prev[j]);
            }
            swap(prev,curr);
        }
        return prev[n];
    }
};