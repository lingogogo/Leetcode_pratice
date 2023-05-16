/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    int* ans = (int *)malloc(sizeof(int)*(n+1));
    *returnSize = n+1;
    for(int i = 0; i <=n; i++)
    {
        int sum = 0;
        int cou = i;
        while(cou != 0)
        {
            sum = sum + cou%2;
            cou/=2;
        }
        ans[i] = sum;
    }
    return ans;
}
