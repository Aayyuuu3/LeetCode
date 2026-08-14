class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int right = 0;
        int freq[256] = {0};
        int max_length = -1;
        while(right < s.size()){
            freq[s[right]] ++;
            while(freq[s[right]] > 2){
                freq[s[left]] --;
                left++;
            }
            max_length = max(max_length , right - left + 1);
            right++;
        }
        return max_length;
    }
};