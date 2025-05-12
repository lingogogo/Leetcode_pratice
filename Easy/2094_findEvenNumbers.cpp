class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> sorted_integers;
        int arr[10] ={0};
        int n = digits.size();
        
        for(int i = 0; i < n ;i++)
        {
            arr[digits[i]]++;
        }
        
        for(int i = 100; i <= 999; i++)
        {
            if(i % 2 == 0)
            {
                int cur = i;
                int temp_arr[10] = {0};
                while(cur != 0)
                {
                    int temp = cur%10;
                    cur/=10;
                    temp_arr[temp]++;
                    if(temp_arr[temp] > arr[temp])
                    {
                        break;
                    }else if(cur == 0){
                        sorted_integers.push_back(i);
                    }
                }
            }
        }
        return sorted_integers;
    }
};
