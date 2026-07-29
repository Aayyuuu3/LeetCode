class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill_5 = 0;
        int bill_10 = 0;
        for(int bill : bills){
            if(bill == 5)
                bill_5 += 1;
            else if(bill == 10){
                if(bill_5 == 0)
                    return false;
                else{
                    bill_5 -= 1;
                    bill_10 += 1;
                }
            }
            else{
                if(bill_5 >= 1 && bill_10 >= 1){
                    bill_5 -= 1;
                    bill_10 -= 1;
                }
                else if(bill_5 >= 3)
                     bill_5 -= 3;
                else return false;
            }
        }
        return true;
    }
};