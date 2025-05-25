class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int largestoutput = 0;
        // palindrome means that the middle output words must be the same.
        int n = words.size();
        
        unordered_map<string,int> unmap;
        
        for(int i = 0; i < n ;i++)
        {
            unmap[words[i]]++;
        }
        int key = 0;
        int same_cha = 0;

        for(auto it = unmap.begin();it!= unmap.end(); it++){
            string temp = it->first;
            reverse(temp.begin(),temp.end());
            if(temp == it->first){ // the same character
                if(it->second % 2 == 0)
                    largestoutput += it->second * 2;
                else if(key == 0 && it->second % 2 == 1){
                    largestoutput += it->second * 2;
                    key = 1;
                }else if(it->second % 2 == 1 && it->second > 2)
                {
                    largestoutput+=(it->second - 1) * 2;
                }
            }else if(unmap.count(temp))
            {
                int val = min(it->second,unmap[temp]);
                unmap[temp]-=val;
                it->second-=val;
                largestoutput+= val*4;
            }
        }
        return largestoutput;
    }
};
