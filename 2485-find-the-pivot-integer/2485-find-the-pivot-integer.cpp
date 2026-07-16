class Solution {
public:
    int pivotInteger(int n) {
        // by mathematical eq
        // x: pivot integer
        // x(x+1) / 2 = n(n+1)/2 - x(x+1)/2 + x
        // x(x+1) / 2 = n(n+1)/2 - x(x-1)/2
        // x*x = n(n+1)/2

        int k = n * (n+1) / 2;
        int x = sqrt(k);
        return (x*x == k)? x : -1 ;
    }
};