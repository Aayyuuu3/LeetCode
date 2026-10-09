class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int open = 0;
        int insertion = 0;
        for(int i = 0; i < n; i ++){
            if(s[i] == '(')
                open ++;
            else{
                if(i + 1 < n && s[i + 1] == ')') i ++;
                else insertion ++;
                
                if(open > 0) open --;
                else insertion ++;
            }
        }
        return insertion + open * 2;
    }
};