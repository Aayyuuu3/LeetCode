class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        else if(x==0) return true;
        int y = x;
        long long z=0;
        while (y>0){
            int r= y%10;
            z = z*10+r;
            y/=10;
        }
        if(z>INT_MAX) return false;
        else if(x==z) return true;
        else return false;
    }
};