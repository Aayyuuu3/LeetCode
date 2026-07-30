class Solution {
public:
    int minimumPushes(string word) {
        if(word.size() <= 8)
            return word.size();
        if(word.size() <= 16){
            int k = word.size() - 8;
            return 8 + 2*k; 
        }
        if(word.size() <= 24){
            int k = word.size() - 16;
            return 24 + 3*k;
        }
        if(word.size() == 25)
            return 52;
        return 56;
    }
};