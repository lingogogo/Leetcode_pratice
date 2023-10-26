class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        int temp = 0;
        int n = nums.size();
        int count = 0;
        while(nums[n-1] < min)
        {
            min = nums[n-1];
            temp = nums[n-1];
            nums.pop_back();
            nums.insert(nums.begin(),temp);
        }
        //cout << nums[0] << endl << nums[n-1] <<endl;
        return min;
    }
};
