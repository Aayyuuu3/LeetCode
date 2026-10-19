class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int index = 0;
        for(int i: nums){
            if(i == target) res.push_back(index);
            index ++;
        }
        return res;
    }
};