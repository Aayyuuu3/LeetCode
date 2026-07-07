class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = 0;
        int r = k-1;
        int n = cardPoints.size();
        int max_sum=0;
        for(int i=l; i<=r; i++)
            max_sum+= cardPoints[i];
        int var = 0;
        int sum = max_sum;
        while(var<k){
            sum = sum - cardPoints[r-var] + cardPoints[n-1-var];
            max_sum = max(max_sum,sum);
            var++;
        }
        return max_sum;

    }
};