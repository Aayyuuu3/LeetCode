class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 2;
        int count = 1;
        int ans = 1;
        while(i <= n && count != k){
            if(n % i == 0){
                count ++ ;
                ans = i;
            }
            i++;
        }
        return (count == k)? ans : -1;
    }
};