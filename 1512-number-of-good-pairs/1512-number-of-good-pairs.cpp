class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int helper[101] = {0};
        for(auto num: nums)
            helper[num]++;
        int pair = 0;
        for(int i=0; i<101; i++){
            if(helper[i]>=2){
                int temp = helper[i];
                pair += temp * (temp-1) / 2;
            }
        }
        return pair;
    }
};