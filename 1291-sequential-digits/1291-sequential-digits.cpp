class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";   // size = 9
        int L = log10(low) + 1;  
        int H = log10(high) + 1;   // 2->10
        int l = 0;
        vector <int> res;
        while(L<=H){
            if(L==10) break;
            string temp = s.substr(l,L);
            int t = stoi(temp);
            if(t>=low && t<=high)
                res.push_back(t);
            l++;
            if(l==(9-L+1)){
                L++;
                l = 0;
            }
        }
        return res;
    }
};