class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int max = arr[0];
        int count_win = 0;
        for(int i = 1; i < arr.size(); i++)
        {
            if(max > arr[i])
            {
                count_win++;
            }else if(max < arr[i])
            {
                max = arr[i];
                count_win=1;
            }
            if(count_win == k) break;
        }
        return max;
    }
};
