class Solution {
public:
    int maxProfit(vector<int>& prices) {
        

        int l_p = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            l_p = min(l_p,prices[i]);

            profit = max(prices[i] -  l_p,profit);

        }
        return profit;

    }
};
