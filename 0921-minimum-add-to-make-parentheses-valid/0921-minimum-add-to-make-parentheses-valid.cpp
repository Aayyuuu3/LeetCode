class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_count = 0;
        int invalid_close = 0;
        for(auto c: s){
            if(c == '(')
                open_count += 1;
            else{
                if(open_count > 0)
                    open_count -= 1;
                else invalid_close += 1;
            }
        }
        return (open_count + invalid_close);
    }
};