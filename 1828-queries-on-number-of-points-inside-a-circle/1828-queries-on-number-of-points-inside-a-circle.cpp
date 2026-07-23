class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector <int> answer;
        for(int i = 0; i < queries.size(); i++){
            int c1 = queries[i][0];
            int c2 = queries[i][1];
            int r = queries[i][2];
            int t = 0;
            for(int j = 0; j < points.size(); j++){
                int x = points[j][0];
                int y = points[j][1];
                if((x-c1)*(x-c1) + (y-c2)*(y-c2) <= r*r )
                    t++;
            }
            answer.push_back(t);
        }
        return answer;
    }
};