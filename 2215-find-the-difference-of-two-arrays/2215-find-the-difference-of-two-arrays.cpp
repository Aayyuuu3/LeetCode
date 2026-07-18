class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> st1;
        unordered_set <int> st2;
        for(auto num: nums1)
            st1.insert(num);
        for(auto num: nums2)
            st2.insert(num);
        vector <int> ans1;
        vector <int> ans2;
        for(auto num: st1){
            if(!st2.count(num))
                ans1.push_back(num);
        }
        for(auto num: st2){
            if(!st1.count(num))
                ans2.push_back(num);
        }
        return {ans1,ans2};
    }
};