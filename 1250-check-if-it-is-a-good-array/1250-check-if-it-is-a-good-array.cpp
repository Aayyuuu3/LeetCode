class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        // we can't make a number smaller than it's gcd (by addition and subtraction)
        // gcd(a,b) = d
        // a.x+b.y = d(k1.x+k2.y) 
        // it will always be a multiple of d 
        // so if d=2 
        //  it will always be 2(c) so either 0 or multiple of 2 but never 1
        int c = nums[0];
        for(int num: nums){
            c = gcd(c,num);
            if(c == 1)
                return true;
        }
        return false;
    }
};