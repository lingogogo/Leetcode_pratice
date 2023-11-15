class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        int n = arr.size();int last = 0;
        sort(arr.begin(),arr.end());
        arr[0] = 1;
        for(int i = 1; i < arr.size();i++)
        {
            if(arr[i] - arr[last] > 1)
            {
                arr[i] = arr[last] + 1;
            }
            last = i;
        }
        return arr[n-1];
    }
};
