class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        int var1=0,var2 = 0;
        int k=0;
        for(int i=0; i<s.size(); i++){
            if(k==0 && s[i]!=goal[i]){
                var1=i;
                k++;
            }
            else if(k==1 && s[i]!=goal[i]){
                var2=i;
                k++;
            }
            else if(k>2) return false;
        }
        if(k==1) return false;
        int freq[26]={0};
        if(k==0){
            for(int i=0;i<s.size();i++){
                freq[s[i]-'a']++;
            if(freq[s[i]-'a']>1)
                return true;
            }
            return false;
        }
        char temp=s[var1];
        s[var1]=s[var2];
        s[var2]=temp;
        if(s==goal) return true;
        else return false;
    }
};