class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int k=1;
        while(k<=digits.size()){
            if(digits[digits.size()-k] != 9){
                digits[digits.size()-k] += 1;
                break;
            }
            else{
                digits[digits.size()-k] = 0;
                k++;
            }
        }
        if(digits[0]==0)
            digits.insert(digits.begin(),1);
        return digits;
    }
};