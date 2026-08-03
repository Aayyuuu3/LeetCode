class Solution {
private:
    int LeftIdxFinder(vector <int> &nums , int low , int high , int target){
        int r = -1;
        while(low <= high){
            int mid = low + (high - low)/2 ;
            if(nums[mid] == target){
                r = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target)
                high = mid - 1;
            else low = mid + 1;
        }
        return r;
    }
    int RightIdxFinder(vector <int> &nums , int low , int high , int target){
        int r = -1;
        while(low <= high){
            int mid = low + (high - low)/2 ;
            if(nums[mid] == target){
                r = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target)
                high = mid - 1;
            else low = mid + 1;
        }
        return r;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int a = LeftIdxFinder(nums,0,n-1,target);
        int b = RightIdxFinder(nums,0,n-1,target);
        return {a,b};   
    }
};