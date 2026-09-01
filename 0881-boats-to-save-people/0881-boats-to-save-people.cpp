class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int l = 0;
        int r = n - 1;
        int boats = 0;
        sort(people.begin(),people.end());
        while(l <= r){
            if((people[l] + people[r]) <= limit){
                boats += 1;
                l ++;
                r --;
            }
            else{
                boats += 1;
                r --;
            }   
        }
        return boats;
    }
};