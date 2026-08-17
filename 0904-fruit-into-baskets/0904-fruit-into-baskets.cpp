class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        int r = 0;
        int max_len = 0;
        unordered_map<int,int>map;
        while(r < fruits.size()){
            map[fruits[r]] ++;
            if(map.size() > 2){
                map[fruits[l]]--;
                if(map[fruits[l]] == 0)
                    map.erase(fruits[l]);
                l++;
            }
            max_len = max(max_len,r - l + 1);
            r++;
        }
        return max_len;
    }
};