class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> unmap;
        int n = answers.size();
        
        for(int i = 0; i < n ;i++)
        {
            unmap[answers[i]]++;
        }
        int output = 0;
        for(auto it = unmap.begin(); it != unmap.end(); it++)
        {
            // if(it->first != 0 && it->first + 1 == it->second )
                // output+=it->first + 1;
            if(it->first != 0 && it->first + 1 >= it->second)
            {
                output+= it->first + 1;
                // output+= (it->second - it->first - 1) * 2;
            }else if(it->first != 0 && it->first + 1 < it->second)
            {
                output+= (it->first + 1) * (it->second / (it->first + 1));
                // output+= (it->first + 1) * (it->second % (it->first + 1));
                if(it->second % (it->first + 1) != 0)
                    output+= (it->first + 1);
            }
            else
                output+=it->second;
        }
        return output;
    }
};
