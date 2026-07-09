class Solution {
public:
    void sortColors(vector<int>& nums) {
        int visited[3] = {0};
        for(int i=0; i<nums.size(); i++){
            visited[nums[i]]++;
        }
        int p = 0;
        int i = visited[0];
        int j = visited[1];
        int k = visited[2];
        while(p!=i)
            nums[p++] = 0;
        while(p!=(i+j))
            nums[p++] = 1;
        while(p!=(i+j+k))
            nums[p++] = 2;
    }
};