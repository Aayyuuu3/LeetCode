class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int max_val = nums[0];
        for(int i=1; i<nums.size(); i++){
            max_val = max(max_val,nums[i]);
            nums[i] = gcd(nums[i],max_val);
        }  
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long sum = 0;
        for(int i=0; i<n/2; i++)
            sum += gcd(nums[i],nums[n-i-1]);
        return sum;
    }
};