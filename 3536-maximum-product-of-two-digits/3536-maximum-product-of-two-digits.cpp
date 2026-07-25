class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        char max1 = '\0'; 
        char max2 = '\0'; 
        for(char c : s){
            if(c > max2){
                if(c > max1){
                    max2 = max1;
                    max1 = c;
                }
                else
                    max2 = c;
            }
        }
        return (max1 - '0') * (max2 - '0');
    }
};