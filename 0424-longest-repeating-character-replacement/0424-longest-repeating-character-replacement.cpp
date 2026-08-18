class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;

        unordered_map <char,int> map;
        int max_len = 0;
        int max_freq = 0;

        while(r < (int)s.size()){
            map[s[r]] ++;
            max_freq = max(max_freq,map[s[r]]);
            if(((r - l + 1) - max_freq) > k){
                map[s[l]] --;
                if(map[s[l]] == 0)
                    map.erase(s[l]);
                l++;
            }
            max_len = max(max_len, r - l + 1);
            r ++;
        }
        return max_len;
    }
};