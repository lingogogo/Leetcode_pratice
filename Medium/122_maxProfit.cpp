class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();

        int min_prices = prices[0];

        for(int i = 1;i < n; i++){
            if(prices[i] > min_prices)
            {
                profit+=prices[i] - min_prices;
                min_prices = prices[i];
            }else{
                min_prices = prices[i];
            }
        }

        return profit;
    }
};
