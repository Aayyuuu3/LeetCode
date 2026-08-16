class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int max_count = 0;
        vector <int> freq(256,0);
        while(r < (int)s.size()){
            freq[s[r]] ++;
            while(freq[s[r]] == 2){
                freq[s[l]]--;
                l++;
            }
            max_count = max(max_count , r - l + 1);
            r++;
        }
        return max_count;
    }
};