class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max_val = 0;
        for(int i=0; i<sentences.size(); i++){
            int var = 0;
            for(int j=0; j<sentences[i].size(); j++){
                if(sentences[i][j] == ' ')
                    var++;
            }
            var++;
            max_val = max(max_val,var);
        }
        return max_val;
    }
};