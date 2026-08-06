class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st;
        for(int i = 0; i < asteroids.size(); i++){
            if(st.empty())
                st.push(asteroids[i]);
            else{
                if(st.top() > 0 && asteroids[i] > 0 || st.top() < 0 && asteroids[i] < 0)
                    st.push(asteroids[i]);
                else if(st.top() > 0 && asteroids[i] < 0){
                    int destroyed = 0;
                    if(abs(st.top()) > abs(asteroids[i]))
                        continue;
                    else if(abs(st.top()) == abs(asteroids[i]))
                        st.pop();
                    else{
                        while(!st.empty() && st.top() > 0 && asteroids[i] < 0){
                            if(abs(st.top()) < abs(asteroids[i]))
                                st.pop();
                            else if(abs(st.top()) == abs(asteroids[i])){
                                st.pop();
                                destroyed = 1;
                                break;
                            }
                            else break;
                        }
                        if(!destroyed && (st.empty() || st.top() < 0))
                            st.push(asteroids[i]);   
                    }
                }
                else st.push(asteroids[i]);
            }
        }
        vector <int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};