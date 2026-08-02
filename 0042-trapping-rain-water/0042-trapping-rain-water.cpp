class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); 
        vector <int> prefix(n,0);
        vector <int> suffix(n,0);
        int max_val = height[0];
        for (int i = 0 ; i < n ; i ++){
            max_val = max(max_val , height[i]);
            prefix[i] = max_val;
        }
        max_val = height[n-1];
        for (int i = n-1 ; i >= 0 ; i --){
            max_val = max(max_val , height[i]);
            suffix[i] = max_val;
        }
        int trapped_water = 0;
        for(int i = 0 ; i < n ; i ++){
            if(height[i] < prefix[i] && height[i] < suffix[i])
                trapped_water += min(prefix[i] , suffix[i]) - height[i];
        }
        return trapped_water;
    }
};