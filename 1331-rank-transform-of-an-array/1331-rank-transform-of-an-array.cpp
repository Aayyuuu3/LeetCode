class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0) return {};
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        int r = 1;
        unordered_map <int,int> mp;
        mp[temp[0]] = r;
        for(int i=1; i<temp.size(); i++){
            if(temp[i]!=temp[i-1]){
                r++;
                mp[temp[i]] = r;
            }
            else
                mp[temp[i]] = r;
        }
        vector <int> result;
        for(int i=0; i<arr.size(); i++){
            int temp = mp[arr[i]];
            result.push_back(temp);
        }
        return result;
    }
};