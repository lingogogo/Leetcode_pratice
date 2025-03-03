class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> leftpiv;
        vector<int> rightpiv;

        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            if(nums[i]>pivot)
            {
                rightpiv.push_back(nums[i]);
            }else if(nums[i] < pivot)
            {
                leftpiv.push_back(nums[i]);
            }
        }
        int rn = rightpiv.size();
        int ln = leftpiv.size();
        int midn = n - rn - ln;
        int temp = 0,temp1 = 0;
        for(int i = 0 ; i<n ;i++)
        {
            if(i<ln)
            {
                nums[i] = leftpiv[temp];
                temp++;
            }else if(i < ln+midn)
            {
                nums[i] = pivot;
                temp++;
            }else{
                nums[i] = rightpiv[temp1];
                temp1++;
            }
        }
        return nums;
    }
};

// triple FOR to check all the condition will be fast than my method
