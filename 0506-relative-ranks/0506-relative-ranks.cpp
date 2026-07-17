class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map <int,int> mp;
        for(int i=0; i<score.size(); i++){
            mp[score[i]] = i;
        }
        sort(score.begin(),score.end(), greater<int>());
        vector <string> ans(score.size());
        int count = 0;
        for(int i=0; i<score.size(); i++){
            int temp = mp[score[i]];
            count++;
            if(count == 1)
                ans[temp] = ("Gold Medal");
            else if(count == 2)
                ans[temp] = ("Silver Medal");
            else if(count == 3)
                ans[temp] = ("Bronze Medal");
            else{
                string t = to_string(i+1);
                ans[temp] = t;
            }
        }
        return ans;
    }
};