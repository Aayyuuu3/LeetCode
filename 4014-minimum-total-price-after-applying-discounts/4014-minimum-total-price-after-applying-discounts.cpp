class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        int i = prices.size()-1;
        int j = discounts.size()-1;
        double price = 0;
        while(i >= 0 && j >= 0){
            price += ((double)prices[i] * (double)(100-discounts[j])) / 100;
            i--;
            j--;
        }
        while(i >=0){
            price += prices[i];
            i--;
        }
        return price;
    }
};