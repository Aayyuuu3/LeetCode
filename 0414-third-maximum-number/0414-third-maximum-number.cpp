class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1 = LLONG_MIN;
        long long max2 = LLONG_MIN;
        long long max3 = LLONG_MIN;
        for(auto it:nums){
            if(it==max1 || it==max2 || it==max3)
                continue;
            if(it>max1){
                max3 = max2; 
                max2 = max1; 
                max1 = it; 
            }
            else if(it>max2){
                max3 = max2;
                max2 = it;
            }
            else if(it>max3)
                max3 = it;
        }
        if(max3!=LLONG_MIN) return max3;
        return max1;
    }
};