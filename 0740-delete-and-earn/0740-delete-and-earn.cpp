class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(10001,0);
        int m = 0;
        for(auto num: nums){
            freq[num] += 1;
            m = max(m,num);
        }
        int prev2 = 0;
        int prev = freq[1];
        for(int i = 2; i <= m; i ++){
            int curr = prev2 + freq[i] * i;
            prev2 = prev;
            prev = max(curr,prev);
        }
        return prev;
    }
};