class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long minsum = 0;
        int n = nums1.size(), m = nums2.size();

        long long num1sum = 0, num2sum = 0;
        int num1zero = 0, num2zero = 0; 

        for(int x : nums1)
        {
            num1sum+=x;
            if(x == 0) num1zero++;
        }

        for(int x : nums2)
        {
            num2sum+=x;
            if(x == 0) num2zero++;
        }
        num1sum+=num1zero;
        num2sum+=num2zero;
        
        if(num1sum > num2sum)
        {
            // check the num2 have the zero or not.
            if(num2zero == 0) return -1;
        }else if(num2sum > num1sum){
            if(num1zero == 0) return -1;
        }else{
            return num1sum;
        }

        return max(num1sum,num2sum);

    }
};
