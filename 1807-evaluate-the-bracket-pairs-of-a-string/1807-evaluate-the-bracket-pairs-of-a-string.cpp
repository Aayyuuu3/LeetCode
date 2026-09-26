class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        int m = knowledge.size();
        for(int i = 0; i < m; i ++)
            mp[knowledge[i][0]] = knowledge[i][1];
        int n = s.size();
        string ans = "";
        string helper = "";
        bool flag = false;
        for(char c: s){
            if(flag){
                helper.push_back(c);
            }
            if(c == '(')
                flag = true;
            else if(c == ')'){
                helper.pop_back();
                flag = false;
                if(mp.find(helper) != mp.end())
                    ans += mp[helper];
                else ans += '?';
                helper = "";
            }
            else{
                if(!flag)
                   ans.push_back(c);
            }
        }
        return ans;
    }
};