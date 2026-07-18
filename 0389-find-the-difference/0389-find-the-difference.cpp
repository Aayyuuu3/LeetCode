class Solution {
public:
    char findTheDifference(string s, string t) {
        int hash[26] = {0};
        for(int i=0; i<s.size(); i++){
            hash[s[i]-'a']++;
            hash[t[i]-'a']--;
        }
        hash[t[t.size()-1]-'a']--;
        for(int i=0; i<26; i++){
            if(hash[i] == -1)
                return char(i + 'a');
        }
        return ' ';
    }
};