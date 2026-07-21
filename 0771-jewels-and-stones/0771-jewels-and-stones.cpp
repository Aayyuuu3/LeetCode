class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int jewel = 0;
        vector <bool> isJewel(128,false);
        for(char c : jewels)
            isJewel[c] = true;
        for(char c : stones){
            if(isJewel[c]) 
                jewel++;
        }
        return jewel;
    }
};