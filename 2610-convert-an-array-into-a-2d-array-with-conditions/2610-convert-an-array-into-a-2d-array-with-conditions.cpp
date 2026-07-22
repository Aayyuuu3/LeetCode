class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector <int> hash(201,0);
        for(auto num: nums)
            hash[num]++;
        int v = *max_element(hash.begin(),hash.end());
        vector <vector<int>> res(v);
        for(int i=0; i < 201; i++){
            int k = hash[i];
            for(int j=0; j < k; j++){
                res[j].push_back(i);
            }
        }
        return res;
    }
};