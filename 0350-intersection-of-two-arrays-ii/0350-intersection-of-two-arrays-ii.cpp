class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int visited1[1001] = {0};
        int visited2[1001] = {0};
        for(auto i: nums1)
            visited1[i]++;
        for(auto i: nums2)
            visited2[i]++;
        nums1.clear();
        for(int i=0; i<1001; i++){
            if(visited1[i] && visited2[i]){
                    int temp = min(visited1[i],visited2[i]);
                    nums1.insert(nums1.end(),temp,i);
            }
        }
        return nums1;
    }
};