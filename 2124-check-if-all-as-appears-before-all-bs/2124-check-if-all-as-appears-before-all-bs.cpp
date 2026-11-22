class Solution {
public:
    bool checkString(string &s) {
        bool b_appeared = false;
        for(char c: s){
            if(c == 'a' && b_appeared) return false;
            if(c == 'b') b_appeared = true;
        }
        return true;
    }
};