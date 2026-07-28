class Solution {
public:
    string smallestPalindrome(string s) {
        int arr[26] = {0};
        int n = s.size();
        for(char c: s)
            arr[c - 'a'] ++;
        int j = 0;
        char c = '\0';
        for(int i = 0; i < 26; i++){
            if(arr[i] != 0){
                if(arr[i] % 2 != 0)
                    c = (char)(i + 'a');
                int k = arr[i]/2;
                int t = 0;
                while(t != k){
                    s[j++] = (char) (i + 'a');
                    t++;
                }
            }
        }
        if(c != '\0')
            s[j++] = c;
        for(int i = n/2-1 ; i >= 0 ; i--){
            s[j++] = s[i];
        }
        return s;
    }
};