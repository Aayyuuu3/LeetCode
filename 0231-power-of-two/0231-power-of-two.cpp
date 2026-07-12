class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        double x = log2(n);
        if(x == floor(x)) return true;
        return false;
    }
};