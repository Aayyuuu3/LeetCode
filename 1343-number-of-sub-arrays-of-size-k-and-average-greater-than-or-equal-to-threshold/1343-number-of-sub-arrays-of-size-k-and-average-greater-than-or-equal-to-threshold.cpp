class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        for(int i = 0; i < k; i++)
            sum += arr[i];
        int ans = 0;
        if(sum >= (threshold * k))
            ans += 1;
        int l = 0;
        int r = k;
        while(r < arr.size()){
            sum = sum - arr[l] + arr[r];
            if(sum >= (threshold*k))
                ans += 1;
            l ++;
            r ++;
        } 
        return ans;
    }
};