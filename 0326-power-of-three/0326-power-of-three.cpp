class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        double t1 = log10(n);
        double t2 = log10(3);
        double t = t1/t2;
        return (t == floor(t));
    }
};