class Solution {
public:
    int findGCD(vector<int>& nums) {
        int m1 = INT_MAX;
        int m2 = INT_MIN;
        for(auto num: nums){
            if(num > m2)
                m2 = num;
            if(num < m1)
                m1 = num;
        }
        return gcd(m2,m1);
    }
};