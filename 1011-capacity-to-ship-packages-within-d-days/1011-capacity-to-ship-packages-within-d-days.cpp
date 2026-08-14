class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;
        for(int weight: weights){
            low = max(low,weight);
            high += weight;
        }
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int w = 0;
            int d = 0;
            for(int i = 0; i < weights.size(); i++){
                w += weights[i];
                if(w > mid){
                    w = 0;
                    d += 1;
                    i --;
                }
            }
            d += 1;
            if(d <= days){
                ans = min(ans,mid);
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};