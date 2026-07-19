class Solution {
public:
    bool isPalindrome(string s) {
        int k = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]>=65 && s[i]<=90)
                s[k++] = (char)(s[i]+32);
            else if((s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57))
                s[k++] = s[i];  
        }
        int i=0;
        k--;
        while(i<k){
            if(s[i] != s[k])
                return false;
            i++;
            k--;
        }
        return true;
    }
};