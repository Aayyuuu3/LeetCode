class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0 && x!=0)) return false;
        else if(x==0) return true;
        int z = 0;
        while (x>z){
            int r= x%10;
            z = z*10+r;
            x/=10;
        }
        if( x==z || x==z/10 ) return true;
        else return false;
    }
};