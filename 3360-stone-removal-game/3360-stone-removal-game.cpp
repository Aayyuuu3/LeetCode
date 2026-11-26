class Solution {
public:
    bool canAliceWin(int n) {
        int move = 0;
        while(true){
            n -= 10 - move;
            move += 1;
            if(n < 0) return (move % 2 == 0); 
        }
    }
};