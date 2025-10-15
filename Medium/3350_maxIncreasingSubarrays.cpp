class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int i = 0;
        while(i < n)
        {
            int j = i + 1;
            
            while( j < n&&nums[j] > nums[j - 1])
            {j++;}
            int subarray1 = j - i;
            j++;
            while(j < n&&nums[j] > nums[j - 1])
            {j++;}
            int subarray2 = j - i - subarray1;
            // cout << "subarray1: " << subarray1 << " subarray2: " << subarray2 << endl;
            // int leng = max(subarray2,subarray1);
            // two conditions: subarray2 > subarray1 && subarray/2 < subarray1
            // subarray/2 > subarray1
            if(subarray2 > subarray1 && subarray2/2 < subarray1){
                res = max(subarray1,res);
            }else if(subarray2/2 >= subarray1){
                res = max(subarray2/2,res);
            }else if(subarray1 > subarray2 && subarray1/2 < subarray2)
            {
                res = max(subarray2,res);
            }else if(subarray1/2 >= subarray2){
                res = max(subarray1/2,res);
            }else{ // Last conditions is subarray1 == subarray2
                res = max(subarray1,res);
            }
            i = i + subarray1;          
        }

        return res;
    }
};
// Better solution
// Thought: We don't need to find out the subarray1 and subarray2
// we just find out the subarray fullfilling the rule and try to find the maximum result.
// It use the min function to find out the subarray2 with the previous subarray min(prev,j - i)
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int i=0, j=1;
        int ans = 0;
        int prev = 0;
        while (j<n){
            if (nums[j] <= nums[j-1]){
                ans = max ({ans, (j-i)/2, min (prev, j-i)});
                prev = j-i;
                i=j;
            }
            j++;
        }
        ans = max ({ans, (j-i)/2, min (prev, j-i)});
        return ans;
    }
};
