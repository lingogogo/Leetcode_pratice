// My method: intuition solution, bad spacecomplexity and timecomplexity.
class Solution {
public:
    int triangularSum(vector<int>& nums){
        int n = nums.size();
        // for(int i  )
        int res = 0;
        int** arr = new int*[n];
        int temp_n = n;
        for(int i =0;i < n; i++)
        {
            arr[i] = new int[temp_n];
            temp_n--;
        }
        int count = n;
        for(int i = 0;i < n; i++){
            for(int j = 0; j < count;j++)
            {
                if(i == 0){
                    arr[i][j] = nums[j];
                }else{
                    arr[i][j] = (arr[i - 1][j] + arr[i - 1][j+1])%10;
                }
            }
            count--;
        }

        return arr[n - 1][0];
    }
};
// use the nums space to solve the problem. (Better solution) 
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = n-1; i > 0; i--) {
            for(int j = 0; j < i; j++) {
                nums[j] = (nums[j] + nums[j+1]) % 10;
            }
        }
        return nums[0];
    }
};
