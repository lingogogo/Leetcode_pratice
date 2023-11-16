class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> dic;
        for(int i =0 ; i < nums.size();i++)
        {
            dic.push_back(std::bitset<32>(nums[i]).to_ulong());
            //cout << bitset<32>(nums[i]).to_ulong() <<endl;
        }
        sort(dic.begin(),dic.end());
        int ans = 0;
        for(int i = 0; i < dic.size(); i++)
        {
            //cout << dic[i] <<endl;
            if(dic[i] != i)
            {
                ans = i;
                break;
            }else if(i == dic.size()-1)
            {
                ans = i + 1;
            }
        }
        int n = nums.size();
        string output;
        while(true)
        {
            int temp = ans%2;
            ans/=2;
            //cout << temp << endl;
            output = to_string(temp) + output;
            if(output.size() == nums.size())
            {
                break;
            }
        }
        return output;
        

        
    }
};
