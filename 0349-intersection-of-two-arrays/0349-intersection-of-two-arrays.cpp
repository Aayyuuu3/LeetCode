class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int visited[1001] = {0};
        vector <int> result;
        for(auto i: nums1){
            if(!visited[i])
                visited[i]++;
        }   
        for(auto i: nums2){
            if(visited[i]){
                result.push_back(i);
                visited[i]=0;
            }
        }
        return result;
    }
};