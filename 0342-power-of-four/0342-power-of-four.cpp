class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        double t1 = log10(n);
        double t2 = log10(4);
        double t = t1/t2;
        return (t == floor(t));
    }
};