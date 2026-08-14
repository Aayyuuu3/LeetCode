class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int missing_numbers = arr[mid] - (mid + 1);
            if(missing_numbers >= k)
                high = mid - 1;
            else low = mid + 1;
        }
        // 2 3 4 7 11; high = 3, low = 4;
        // missing_numbers = arr[high] - (high + 1);
        // ans = arr[high] + more
        // more = k - missing_numbers
        // ans = arr[high] + k - (arr[high] - (high + 1))
        // ans = k + high + 1
        // ans = k + low
        return low + k;
    }
};