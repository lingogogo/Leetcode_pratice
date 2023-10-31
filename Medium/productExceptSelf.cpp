class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int n = nums.size();

        int arr1[n+1];
        int arr2[n+1];
        arr1[0] = 1;
        arr2[n] = 1;
        for(int i =1; i < n; i++)
        {
            arr1[i] = nums[i - 1]*arr1[i-1];
        }
        for(int i = n-1; i >=0; i--)
        {
            arr2[i] = nums[i]*arr2[i+1];
        }
        for(int i = 0; i < n; i++)
        {
            output.push_back(arr1[i]*arr2[i+1]);
        }
        return output;
    }
};
