class Solution {
public:
    int arraySign(vector<int>& nums) {
        int arr[1] = {0};
        int flag = 0;
        for(auto it: nums){
            if(it == 0){
                flag = 1;
                break;
            }
            if(it<0)
                arr[0]++;
        }
        if(flag) return 0;
        return (arr[0] % 2 ==0)? 1:-1;
    }
};