class Solution {
public:
    int lengthOfLastWord(string s) {
        int c = -1;
        int n = s.size();
        while(true){
            if(s[n-1] != ' ')
                break;
            n--;
            if(n==0) break;
        }
        if(!n) return 0;
        for(int i=0; i<n; i++){
            if(s[i]==' ')
                c = i+1;
        }
        if(c == -1) return n;
        return n-c;
    }
};