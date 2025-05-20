class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> arr(n,0);
        for(int i = 0; i < queries.size(); i++)
        {
            arr[queries[i][0]]++;
            if(queries[i][1]+1 < n)
                arr[queries[i][1] + 1]--;
        }
        // [1, 0 ,0];
        for(int i = 1; i < n; i++)
        {
            arr[i] = arr[i - 1] + arr[i];
        }
        // [1,1,1];
        for(int i = 0; i < n; i++)
        {
            // cout << nums[i] << " " << arr[i] << endl;
            nums[i] -= arr[i];
            if(nums[i] > 0)
                return false;
        }
        return true;

        
    }
};
