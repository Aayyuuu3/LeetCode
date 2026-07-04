class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(auto it: s){
            if(it == '[' || it == '(' || it == '{')
                st.push(it);
            else{
                if(it == ']' && st.size()){
                    if(st.top()!= '[')
                        return false;
                }
                else if ( it == '}'&& st.size() ){
                    if(st.top()!= '{')
                        return false;
                }
                else if(it == ')' && st.size()){
                    if(st.top()!= '(')
                        return false;
                }
                else return false;
                st.pop();
            }
        }
        if(st.size()!=0) return false;
        else return true;
    }
};