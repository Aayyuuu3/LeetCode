class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return false;
        int k=1;
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i+1]<arr[i]){
                k = i+1;
                break;
            }
            else if(arr[i+1]>arr[i])
                continue;
            else return false;
        }
        if(k==1) return false;
        for(int i=k; i<arr.size()-1; i++){
            if(arr[i+1]>=arr[i])
                return false;
        }
        return true;
    }
};