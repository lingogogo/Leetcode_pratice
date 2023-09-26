class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> hash_table;
        for(auto i = nums.begin();i != nums.end(); i++)
        {
            cout << *i << endl;
            if(hash_table.find(*i) != hash_table.end())
            {
                hash_table[*i]+=1;
            }else
            {
                hash_table.insert(pair<int,int>(*i,1));
            }
            
        }
        vector<int> output;
        int max = 0;
        int index = 0;
        for(int i = 0; i < k ;i++)
        {
            for(auto j = hash_table.begin(); j != hash_table.end(); j++)
            {
                if(j->second > max)
                {
                    max = j->second;
                    index = j->first;
                }
            }
            output.push_back(index);
            hash_table.erase(index);
            max = 0;
        }
        return output;

    }
};
