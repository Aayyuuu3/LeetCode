class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = 0;
        int n = cardPoints.size();

        int max_points = 0;
        int points = 0;
        
        for(int i = l; i < k; i++)
            points += cardPoints[i];
        max_points = points;
        
        int j = 1;
        while(j <= k){
            points -=  cardPoints[k - j];
            points += cardPoints[n - j];
            max_points = max(max_points,points);
            j++;
        }
        return max_points;
    }
};