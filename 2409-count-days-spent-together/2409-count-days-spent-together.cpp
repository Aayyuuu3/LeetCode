class Solution {
private:    
    int Days(string date){
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        int dayCnt = 0;
        for(int i = 0; i < month - 1; i ++)
            dayCnt += days[i];
        dayCnt += day;
        return dayCnt;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob){
        int aStart = Days(arriveAlice);
        int bStart = Days(arriveBob);
        int aEnd = Days(leaveAlice);
        int bEnd = Days(leaveBob);
        int start = max(aStart, bStart);
        int end = min(aEnd, bEnd);
        return max(0, end - start + 1);
    }
};