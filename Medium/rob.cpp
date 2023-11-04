class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int dy[n];
        if(n >= 2){
            dy[0] = nums[0];
            dy[1] = nums[1];
            //cout << dy[0] << " " << dy[1] << endl;
        }
        int before_max = 0;
        for(int i = 2;i < n;i++)
        {
            for(int j = 0; j < i-1; j++)
            {
                if(before_max < dy[j])
                    before_max = dy[j];
            }
            dy[i] = nums[i] + before_max;
            //cout << dy[i] <<endl;
        }
        int output = 0;
        for(int i =1; i < n; i++)
        {
            output = max(dy[i-1],dy[i]);
            
        }
        return output;


    }
};
