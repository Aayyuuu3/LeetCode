class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> s;
        for(auto i: nums){
            auto it = s.find(i); 
            if(it != s.end())
                return true;
            s.insert(i);
        }
        return false;
    }
};