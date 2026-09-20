class Solution {
public:
    int reverseDegree(string s) {
        int revdegree = 0;
        for(int i = 0; i < s.size(); i++){
            int idx = 'z' - s[i] + 1;
            revdegree += idx * (i + 1);
        }
        return revdegree;
    }
};