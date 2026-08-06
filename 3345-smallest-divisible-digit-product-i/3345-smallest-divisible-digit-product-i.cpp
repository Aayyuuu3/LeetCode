class Solution {
public:
    int smallestNumber(int n, int t) {
        while(n % 10 != 0){
            int temp = 1;
            int k = n;
            while(k > 0){
                int p = k % 10;
                temp *= p;
                k /= 10;
            }
            if(temp % t == 0)
                return n;
            n += 1;
        }   
        return n;
    }
};