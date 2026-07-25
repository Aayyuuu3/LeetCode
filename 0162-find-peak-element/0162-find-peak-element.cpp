class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // we compare mid and we go towards uphill
        // eg mid ele = 5
        // 5 6 7 3  => 7 peak element
        // 5 6 7 end of list nums[n] = - oo so 7 peak element 
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            int mid = l + (r-l)/2 ; 
            if(nums[mid] < nums[mid+1])
                l = mid + 1;
            else
                r = mid; 
        }
        return l;
    }
};