class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int l = 0;
        int r = n - 1;
        int score = 0;
        while(l <= r){
            if(tokens[l] <= power){
                power -= tokens[l];
                score += 1;
                l ++;
            }
            else{
                if(score >= 1 && l != r){    // power + tokens[r] > tokens[l]  
                    power += tokens[r];      // always work as tokens[r] >= tokens[l] 
                    score -= 1;             // if p + tr = tl first score - 1 then + 1
                    r --;
                }
                else break;
            }
        }
        return score;
    }
};