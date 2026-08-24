class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0){
            N = -N;
            x = 1/x;
        }
        if(N == 0)
            return 1;
        int half = N/2;
        double power = myPow(x,half);
        if(N % 2)
            return power*power*x;
        else return power*power;
    }
};