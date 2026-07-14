class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int c = 1;
        while(i>=0 && j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[m+n-c] = nums1[i];
                i--;
            }
            else{
                nums1[m+n-c] = nums2[j];
                j--;
            }
            c++;
        }
        while(j>=0){
            nums1[m+n-c] = nums2[j];    
            j--;
            c++;
        }
    }
};