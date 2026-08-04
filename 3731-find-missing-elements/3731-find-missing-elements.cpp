class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector <int> ans;
        int m1 = *min_element(nums.begin(),nums.end());
        int m2 = *max_element(nums.begin(),nums.end());
        int n = m2 - m1;
        n += 1;
        vector<int> freq(n, 0);
        for(int num: nums)
            freq[num-m1]++;
        for(int i = 0; i < n; i++){
            if(freq[i] == 0)
                ans.push_back((i+m1));
        }
        return ans;
    }
};