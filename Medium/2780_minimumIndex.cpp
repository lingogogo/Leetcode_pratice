class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,vector<int>> mmap;
        int n = nums.size();
        vector<int> temp(2,0);
        for(int i = 0; i < n; i++)
        {
            if(mmap.find(nums[i]) == mmap.end()){
                mmap[nums[i]] = temp;
                mmap[nums[i]][0]++;
            } 
            else{
                mmap[nums[i]][0]++;
                // cout << mmap[nums[i]]
            }
                
        }

        // int minimuindex = 0;
        // unordered_map<int,int> before_mmap;
        for(int i = 0; i < n; i++)
        {
            // i mean the first separate point
            // first, find the mmap[nums[i]]
            
            mmap[nums[i]][0]--;
            mmap[nums[i]][1]++;
            // check the first subarray
            if(mmap[nums[i]][1]*2 > i + 1){
                // check the second subarray
                if(mmap[nums[i]][0] * 2 > n - i - 1) return i;
            }
        }
        return -1;
    }
};


// Boyer-Moore Majority Voting Algorithm
// This algorithm efficiently finds a majority element (if it exists) in linear time without using extra space.
// The key observation behind it is that if an element appears more than n/2 times, then it must remain after canceling out other elements. 
// By iterating through nums while maintaining a candidate element and a counter, we can determine the element x that appears the most.
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // Find the majority element
        int x = nums[0], count = 0, xCount = 0, n = nums.size();
        for (auto& num : nums) {
            if (num == x) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                x = num;
                count = 1;
            }
        }

        // Count frequency of majority element
        for (auto& num : nums) {
            if (num == x) {
                xCount++;
            }
        }

        // Check if valid split is possible
        count = 0;
        for (int index = 0; index < n; index++) {
            if (nums[index] == x) {
                count++;
            }
            int remainingCount = xCount - count;
            if (count * 2 > index + 1 && remainingCount * 2 > n - index - 1) {
                return index;
            }
        }
        return -1;
    }
};
