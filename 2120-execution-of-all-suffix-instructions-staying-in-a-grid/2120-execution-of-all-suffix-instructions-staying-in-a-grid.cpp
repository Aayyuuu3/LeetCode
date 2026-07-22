class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector <int> ans;
        int k = 0;
        while(k != s.size()){
            int r = startPos[0];
            int c = startPos[1];
            int t = 0;
            for(int i = k; i < s.size(); i++){
                if(s[i] == 'R' && (c+1)<n){
                    t++;
                    c += 1;
                }
                else if(s[i] == 'L' && (c-1)>=0){
                    t++;
                    c -= 1;
                }
                else if(s[i] == 'U' && (r-1)>=0){
                    t++;
                    r -= 1;
                }
                else if(s[i] == 'D' && (r+1)<n){
                    t++;
                    r += 1;
                }
                else break;
            }
            k++;
            ans.push_back(t);
        }
        return ans;
    }
};