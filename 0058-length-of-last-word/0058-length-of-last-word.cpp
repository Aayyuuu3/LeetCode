class Solution {
public:
    int lengthOfLastWord(string s) {
        int c = 0;
        int n = s.size();
        int a = -1;
        int b = -1;
        for(int i = n-1; i>=0; i--){
            if(!c && s[i] != ' '){
                b = i;
                c = 1;
            }
            else if(c && s[i] == ' '){
                a = i;
                break;
            }
        }
        if(b == -1) return 0;
        if(a == -1) return b+1;
        return b-a;
    }
};