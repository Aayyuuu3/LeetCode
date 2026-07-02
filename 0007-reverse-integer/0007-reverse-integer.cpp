class Solution {
public:
    int reverse(int x) {
        long long t = x;
        long long y = abs(t);
        long long z = 0;
        while(y>0){
            int r = y % 10;
            z = z*10 + r;
            y/=10;
        }
        if(z>INT_MAX || z<INT_MIN) return 0;
        else if(x<0) return -z;
        else return z;
    }
};