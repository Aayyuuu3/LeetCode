class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m > n / k)
            return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int bouquet_count = 0;
            int days = 0;
            for(int i = 0; i < n; i++){
                if(bloomDay[i] <= mid)
                    days++;
                else days = 0;
                if(days == k){
                    bouquet_count ++;
                    days = 0;
                }
                if(bouquet_count == m){
                    ans = min(mid,ans);
                    high = mid - 1;
                    break;
                }
            }
            if(bouquet_count != m)
                low = mid + 1;
        }
        return (ans != INT_MAX)? ans : -1;
    }
};