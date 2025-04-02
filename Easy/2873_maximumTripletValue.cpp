class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxtrip = 0;

        int n = nums.size();

        for(int i = 0;i < n - 2; i++)
        {
            for(int j = i + 1; j < n - 1; j++)
            {
                for(int k =  j + 1; k < n; k++){
                    long long val = (long(nums[i]) - nums[j])*nums[k];
                    maxtrip = max(val, maxtrip);
                }
            }
        }

        if(maxtrip < 0) return -1;
        else return maxtrip;

        
    }
};
// second method
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxtrip = 0;

        int n = nums.size();
        long long vali = nums[0];
        long long valij = INT_MIN;
        long long valijk = 0;
        for(int i = 1; i < n - 1; i++)
        {
            valij = max(valij,vali - nums[i]);
            vali = max(vali,(long long)nums[i]);
            valijk = max(valijk, valij * nums[i + 1]);
        }
        maxtrip = valijk;
        if(maxtrip < 0) return -1;
        else return maxtrip;

        
    }
};
