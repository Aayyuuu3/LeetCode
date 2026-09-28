class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0;
        int counter = 0;
        for(char c: s){
            if(c == '(')
                counter += 1;
            else if(c == ')'){
                max_depth = max(max_depth,counter);
                counter -= 1;
            }
        }
        return max_depth;
    }
};