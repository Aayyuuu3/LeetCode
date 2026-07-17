class Solution {
public:
    bool isPrime(int n){
        for(int i=2; i*i<=n; i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for(int i=0, j=n-1; i<n && j>=0; i++, j--){
            if(nums[i][i]>=2 && isPrime(nums[i][i]))
                ans = max(ans,nums[i][i]);
            if(nums[i][j]>=2 && isPrime(nums[i][j]))
                ans = max(ans,nums[i][j]);
        }
        return (ans != INT_MIN)? ans : 0;
    }
};