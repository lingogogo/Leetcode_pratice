class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long countparis = 0;
        sort(nums.begin(), nums.end()); // 0, 1, 4, 4, 5, 7;
        int n = nums.size();
        int left = 0, right = n - 1;

        // window move

        // upper
        while(left < right)
        {
            int temp = nums[left] + nums[right];
            if(temp > upper) right--;
            else{
                countparis += right - left;
                left++;
            }
        }
        // lower
        left = 0, right = n - 1;
        while(left < right)
        {
            int temp = nums[left] + nums[right];
            if(temp >= lower) right--;
            else{
                countparis -= right - left;
                left++;
            }
        }
        return countparis;
    }
};
