class Solution {
public:
    bool isThree(int n) {
        int count = 2;
        int k = n/2;
        for(int i=2; i<=k; i++){
            if(n % i == 0)
                count++;
        }
        return (count == 3);
    }
};