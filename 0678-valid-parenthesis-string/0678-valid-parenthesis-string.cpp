class Solution {
public:
    bool checkValidString(string s) {
        int min_check = 0;
        int max_check = 0;   // range of count of ();
        for(auto c: s){
            if(c == '('){
                min_check ++;
                max_check ++;
            }
            else if(c == ')'){
                min_check --;
                max_check --;
            }
            else{
                min_check --;
                max_check ++;
            }
            if(min_check < 0)
                min_check = 0;
            if(max_check < 0)            // for edge case s: )....
                return false;
        }
        return  (min_check == 0);
    }
};