class Solution {
public:
    bool sumGame(string num) {
        int half = num.size()/2;
        int count1 = 0;
        int count2 = 0;
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < half; i++){
            if(num[i] == '?')
                count1 ++;
            else sum1 += num[i] - '0';
            if(num[i + half] == '?')
                count2 ++;
            else sum2 += num[i + half] - '0';
        }
        if((count1 + count2) % 2 != 0)
            return true;    // last chance: Alice (will make the sum unequal);
        return (2 * (sum1 - sum2) != 9 * (count2 - count1));
    }
};