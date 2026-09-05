class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](const vector<int>& a, const vector<int>& b){
            return a[1] > b[1];
        });
        int size = boxTypes.size();
        int units = 0;
        for(int i = 0; i < size; i++){
            if(truckSize == 0)
                break;
            if(boxTypes[i][0] <= truckSize){
                units += (boxTypes[i][1] * boxTypes[i][0]);
                truckSize -= boxTypes[i][0];
            }
            else{
                units += (boxTypes[i][1] * truckSize);
                truckSize = 0;
            }
        }
        return units;
    }
};