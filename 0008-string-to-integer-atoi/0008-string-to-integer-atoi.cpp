class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        while(i < n && s[i] == ' ')
            i++;
        if(i == n)
            return 0;
        int sign = 1;
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
            sign = 1;
            i++;
        }
        while(i < n && s[i] == 48)
            i++;
        if(i == n)
            return 0;
        long long ans = 0;
        while(i < n && s[i] >= 48 && s[i] <= 57){
            int r = s[i] - 48;
            ans *= 10;
            ans += r;
            i++;
            if(sign*ans >= INT_MAX)
                return INT_MAX;
            if(sign*ans <= INT_MIN)
                return INT_MIN;
        }
        return sign * ans;
    }
};