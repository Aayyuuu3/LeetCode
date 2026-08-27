class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int freq[50000] = {0};
        int max_freq = 0;
        for(int num: nums){
            freq[num] ++;
            max_freq = max(max_freq,freq[num]);
        }
        for(int i = 0; i < 50000; i++)
            freq[i] = 0;
        int min_len = INT_MAX;
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            freq[nums[r]] ++;
            while(freq[nums[r]] == max_freq){
                min_len = min(min_len,r - l + 1);
                freq[nums[l]] --;
                l++;
            }
        }
        return min_len;
    }
};