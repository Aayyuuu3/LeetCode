class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector <int> arr(2001,0);
        for(int num: nums)
            arr[num + 1000] = 1;
        int max_val = INT_MIN;
        for(int i=0; i< 1000; i++){
            if(arr[i] == 1 && arr[2000-i] == 1){
                int k = 1000 - i;
                max_val = max(max_val, k);
            }
        } 
        return (max_val != INT_MIN)? max_val : -1;
    }
};