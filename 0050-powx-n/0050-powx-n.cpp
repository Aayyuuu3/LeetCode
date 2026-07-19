class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        else if(n == 0) return 1;
        long long v = n;
        v = abs(v);
        double ans = 1;
        double var = x; 
        while(v > 0){
            if(v % 2 != 0){
                ans *= var;
                v--;
            }
            var *= var;
            v /= 2;
        }
        return (n > 0)? ans:1/ans;
    }
};