class Solution {
public:
    string countAndSay(int n) {
        string countandsay = "1";

        for(int i = 1; i < n ; i++)
        {
            int k = countandsay.size();
            // unordered_map<int,int> unmap;
            string temp_countandsay;
            int start = 0;
            int frequency[10]={0};
            int present_now = 0;
            int present_pre = 0;
            while(start < k)
            {
                
                // cout << start << endl;
                present_now = countandsay[start] - '0';
                frequency[countandsay[start] - '0']++;
                if(present_now != present_pre && start != 0)
                {
                    temp_countandsay += to_string(frequency[present_pre]) + to_string(present_pre);
                    frequency[present_pre] = 0;
                }
                start++;
                
                present_pre = present_now;
            }
            temp_countandsay += to_string(frequency[present_pre]) + to_string(present_pre);
            countandsay = temp_countandsay;
        }

        return countandsay;
    }
};
