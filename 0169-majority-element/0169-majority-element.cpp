class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int var = 0;
        int element = 0;
        for(int num: nums){
            if(var == 0)
                element = num;
            if(num == element)
                var++;
            else var--;
        }
        return element;
    }
};