class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0;
        long long r = sqrt(c);
        while(l <= r){
            long long sum = l*l + r*r;
            if(sum == c)
                return true;
            else if(sum > c)
                r--;
            else l++;
        }
        return false;
    }
};