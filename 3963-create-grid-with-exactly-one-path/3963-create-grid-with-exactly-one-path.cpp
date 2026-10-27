class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string row(n, '#');
        row[n - 1] = '.';
        vector<string> res(m, row);
        res[0] = string (n, '.');
        return res;
    }
};