class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(int i = 0; i < word.size(); i++)
            freq[word[i] - 'a'] ++;
        sort(freq.begin(),freq.end());
        int pushes = 0;
        for(int i = 25; i >= 0; i--){
            if(freq[i] == 0)
                break;
            if(i >= 18){
                pushes += freq[i];
            }
            else if(i >= 10){
                pushes += 2*freq[i];
            }
            else if(i >= 2){
                pushes += 3*freq[i];
            }
            else pushes += 4*freq[i];
        }
        return pushes;
    }
};