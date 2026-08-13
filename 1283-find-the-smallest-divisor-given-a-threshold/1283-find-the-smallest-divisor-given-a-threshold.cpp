class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        if(n == threshold)
            return high;
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int result = 0;
            for(int num: nums){
                result += ceil((double)num/mid);
                if(result > threshold)
                    break;
            }
            if(result <= threshold){
                ans = min(mid,ans);
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};