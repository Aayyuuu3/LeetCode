class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // odd = n*n;
        // even = n*(n+1);
        // gcd(n*n,n(n+1));
        // n * gcd(n,n+1);
        // n * 1 => n
        return n;
    }
};