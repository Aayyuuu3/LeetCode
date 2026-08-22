class Solution {
public:
    bool checkDivisibility(int n) {
        int k = n;
        long long sum = 0;
        long prod = 1;
        while(n){
            int r = n % 10;
            n /= 10;
            sum += r;
            prod *= r;
        }
        return (k % (sum+prod) == 0);
    }
};