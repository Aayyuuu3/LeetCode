class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1) return 1;
        int c = n * (n+1) / 2;
        for(int i=1; i<n; i++){
            int k = i * (i+1) / 2;
            if( k == (c-k+i))
                return i;
        }
        return -1;
    }
};