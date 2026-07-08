class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        int visited[201] = {0};
        for(int i=0; i<nums.size(); i++){
            visited[nums[i]+100]++;
            if(visited[nums[i]+100]==1)
                nums[k++] = nums[i]; 
        }
        return k;
    }
};