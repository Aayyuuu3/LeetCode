class Solution {
public:
    bool isPrime(int n){
        if(n <= 1) return false;
        if(n == 2 || n == 3) return true;
        for(int i=2; i*i<=n; i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        int visited[101] = {0};
        for(auto num : nums)
            visited[num] ++ ;
        for(int i=0; i<101; i++){
            if(visited[i]<=1)
                continue;
            bool temp = isPrime(visited[i]);
            if(temp)
                return true;
        }
        return false;
    }
};