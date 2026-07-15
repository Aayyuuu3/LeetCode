class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        int visited[26] = {0};
        for(int i=0; i<s.size(); i++)
            visited[s[i]-'a']++;
        for(int i=0; i<t.size(); i++)
            visited[t[i]-'a']--;
        for(int i=0; i<26; i++){
            if(visited[i])
                return false;
        }
        return true;
    }   
};