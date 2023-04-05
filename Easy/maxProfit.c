int maxProfit(int* prices, int pricesSize){
    if(pricesSize == 1)
    {
        return 0;
    }
    int min = prices[0];
    int profit =0;
    
    for(int i = 0; i < pricesSize; i++)
    {
        if(min > prices[i])
            min = prices[i];
        
        if(profit < (prices[i] - min))
        {
            profit = prices[i] - min;
        }
        
    }
    return profit;

    
}
