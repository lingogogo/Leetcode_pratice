// From MarkSPhilip31 website.
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> output;
        vector<int> memory(nums.size(),0);
        if(nums.size() == 1) return nums;
        //找質數
        //質數特性: 
        sort(nums.begin(),nums.end());
        
        // int check = 1;
        int maxv = 0;
        for(int i = 1;i < nums.size(); i++){
            for(int j = 0; j < i;j++)
            {
                if(nums[i] % nums[j] == 0 && memory[i] < memory[j] + 1){
                    memory[i] = memory[j] + 1;
                    if(maxv < memory[i])
                    {
                        maxv = memory[i];
                    }
                }
                
            }
        }
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     cout << memory[i] << endl;
        // }
        // the number will be [1 , 2 ,3 ,4] in the same subset.
        int temp = -1;
        for(int i = nums.size() - 1; i >-1;i--)
        {
            if(maxv == memory[i] && (temp%nums[i] == 0 || temp == -1))
            {
                output.push_back(nums[i]);
                maxv--;
                temp = nums[i];
            }
        }
        return output;
    }
};
