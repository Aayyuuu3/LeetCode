class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())
            return "";
        int l = 0;
        int r = 0;
        int idx1 = -1;
        int idx2 = -1;
        int min_len = INT_MAX;

        vector <int> freq(256,0);
        for(char c: t) freq[c] ++;
        int count = t.size();

        while(r < s.size()){
            freq[s[r]] --;
            if(freq[s[r]] >= 0)
                count --;
            while(count == 0){
                if((r - l + 1) < min_len){
                    idx1 = l;
                    idx2 = r;
                    min_len = r - l + 1;
                }
                freq[s[l]] ++;
                if(freq[s[l]] > 0)
                    count ++;
                l ++;
            }
            r ++;
        }
        if(idx1 == -1)
            return "";
        return s.substr(idx1, min_len);
    }
};