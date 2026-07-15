class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = n*n;
        int even = n*(n+1);
        int ans = 1;
        for(int i=2; i<=(odd)/2; i++){
            if(odd % i ==0 && even % i ==0)
                ans = i;
        }
        return ans;
    }
};