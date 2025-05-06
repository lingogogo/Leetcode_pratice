//space complexity: O(N)
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> output;

        int n = nums.size();

        for(int i = 0;i < n; i++)
        {
            output.push_back(nums[nums[i]]);
        }

        return output;
    }
};


// space complexity: O(1)

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        // int val = 0;
        for(int i = 0;i < n; i++)
        {
            // cout << nums[i] << endl;
            nums[i] += 1000*(nums[nums[i]]%1000);
            // cout << nums[i] << endl;
        }

        for(int i = 0;i <n;i++)
        {
            nums[i]/=1000;
        }

        return nums;
    }
};
