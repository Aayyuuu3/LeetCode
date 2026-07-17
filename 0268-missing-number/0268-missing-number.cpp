class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n = nums.size();
        long long sum = n * (n+1) /2;
        long long h = 0;
        for(auto num: nums)
            h += num;
        return (sum-h) ;
    }
};