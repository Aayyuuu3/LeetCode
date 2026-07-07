class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        long long num=0;
        while(n>0){
            int r = n%10;
            sum+= r;
            if(r)
                num = num*10 + r;
            n/=10;
        }
        long long num1 = 0;
        while(num>0){
            int r = num%10;
            num1 = num1*10 + r;
            num/= 10;
        }
        return num1*sum;
    }
};