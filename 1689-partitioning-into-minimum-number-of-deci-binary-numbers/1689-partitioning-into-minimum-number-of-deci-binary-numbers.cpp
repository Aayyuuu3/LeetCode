class Solution {
public:
    int minPartitions(string n) {
        char max_ele = *max_element(n.begin(), n.end());
        return max_ele - '0';
    }
};