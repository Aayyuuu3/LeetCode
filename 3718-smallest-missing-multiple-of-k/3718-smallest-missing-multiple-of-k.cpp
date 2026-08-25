class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int>hash(101,0);
        for(int num: nums)
            hash[num] = 1;
        int i;
        for(i = k; i < hash.size(); i += k){
            if(hash[i] == 0)
                return i;
        }
        return i;
    }
};