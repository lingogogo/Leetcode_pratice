int maxIceCream(int* costs, int costsSize, int coins) {
    int costarr[100002] = {0};
    // for(int i = 0 ;i <= 1e5; i++) costarr[i] = 0;

    for(int i = 0 ;i < costsSize; i++)
    {
        costarr[costs[i]]++;
    }
    int maxbars = 0;
    for(int i = 1;i <= 100001 && coins > 0; i++)
    {
        if(costarr[i] > 0){
            // check the coins we can buy the value in the costs.
            int buys = coins/i;
            int hold = fmin(buys,costarr[i]);
            coins -= hold * i;
            maxbars += hold;
        }
    }

    return maxbars;
}
