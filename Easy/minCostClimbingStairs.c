//my ways is shortsight, because I cannot take the costSize into consideration.
int minCostClimbingStairs(int* cost, int costSize){
    if(costSize == 1)
    {
        return cost[0];
    }
    int* com_int = (int*)malloc(sizeof(int)*2);
    int start = 0;
    int sum_cost = cost[start];
    // int top = costSize
    while(start < costSize)
    {
        //how many step I want
        if(start+1 >= costSize || start+2 >= costSize)
        {
            com_int[0] = sum_cost;
            break;
        } 
        if(cost[start + 1] >=cost[start + 2]) start+=2;
        else start+=1;
        // calculate my cost first
        sum_cost+=cost[start];
    }
    start = 1;
    sum_cost = cost[start];
    while(start < costSize)
    {
        //how many step I want
        if(start+1 >= costSize || start+2 >= costSize) 
        {
            com_int[1] = sum_cost;
            break;
        } 
        if(cost[start + 1] >=cost[start + 2]) start+=2;
        else start+=1;
        // calculate my cost first
        sum_cost+=cost[start];
    }
    if(com_int[0]>com_int[1]) return com_int[1];
    else return com_int[0];

}
//bottom up
int minCostClimbingStairs(int* cost, int costSize){
    for(int i=2; i<costSize; i++)
        cost[i] += cost[i-1] < cost[i-2] ? cost[i-1] : cost[i-2];
    return cost[costSize-1] < cost[costSize-2] ? cost[costSize-1] : cost[costSize-2];
}
// top-down
#define MIN(a,b) (((a)<(b))?(a):(b))

int minCostClimbingStairs(int* cost, int costSize){
    int dpNPlus2 = 0;
    int dpNPlus1 = cost[costSize - 1];
    int tmp;

    for (int i = costSize - 2; i >= 0; i--)
    {
        tmp = cost[i] + MIN(dpNPlus1, dpNPlus2);
        dpNPlus2 = dpNPlus1;
        dpNPlus1 = tmp;
    }

    return MIN(dpNPlus1, dpNPlus2);
}
