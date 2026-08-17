class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        vector <int> freq(3,0);
        while(r < s.size()){
            freq[s[r] - 'a'] ++;
            while(freq[0] >= 1 && freq[1] >= 1 && freq[2] >= 1){
                ans += s.size() - r ;
                freq[s[l] - 'a']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};