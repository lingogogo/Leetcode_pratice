class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int count = 0;
        int sum_difference = 0;
        int n = differences.size();
        // for(int i = 0; i < n; i++)
        // {
        //     sum_difference+=differences[i]; // means that the hidden[k - 1] - hidden[0]; k = n + 1;
        // }
        vector<long long> prefixsum(n,0);
        prefixsum[0] = differences[0];
        int max_dif = differences[0], min_dif = differences[0];
        for(int i = 1; i < n; i++)
        {
            prefixsum[i] = prefixsum[i-1] + differences[i];// [1,-2,2]
            if(max_dif < prefixsum[i]){
                max_dif = prefixsum[i];
            }
            if(min_dif > prefixsum[i]){
                min_dif = prefixsum[i];
            }
        }
        // max = 2, min = -2; give the first element and we can get the max and min value in the hidden array.
        // Give all array.
        for(int i = lower; i <= upper; i++){
            // we have the first element in hidden array
            // use max_dif and min_dif to check the result
            if(i + max_dif <= upper && i + min_dif >= lower)
                count++;
        }
        // the fast method is (upper - lower + 1) - (range of sequence)
        // (upper - lower + 1) is like the above for loop for check the upper and lower value.
        // so there are upper - lower + 1 in first element.
        // range of sequence means that the difference between max_dif and min_dif.
        // the value of range must be smaller than upper - lower + 1, or it can not get the proper hidden array.
        return count;

    }
};
