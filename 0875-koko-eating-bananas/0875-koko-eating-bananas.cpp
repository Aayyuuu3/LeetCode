class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        if(piles.size() == h)
            return r;
        int ans = 0;  
        while(l <= r){
            int k = l + (r - l) / 2;
            long long hour = 0;
            for(int pile: piles)
                hour += ceil(double(pile) / k);
            if(hour > h)
                l = k + 1;
            else{
                ans = k;
                r = k - 1; 
            }
        }
        return ans;
    }
};