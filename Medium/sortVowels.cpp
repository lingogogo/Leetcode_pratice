class Solution {
public:
    string sortVowels(string s) {
        vector<int> index;
        map<char,int> order_map;
        string vowels = "aeiouAEIOU";
        for(int i =0; i < 10; i++)
        {
            order_map[vowels[i]] = 0;
        }

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e'||s[i] == 'i' || s[i] == 'o'||s[i] == 'u'
            || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {

                order_map[s[i]]++;
                index.push_back(i);
            }
        }

        map<char,int>::iterator it = order_map.begin();
        for(int i = 0; i < index.size(); i++)
        {
            if(it->second==0)
            {
                while(it!=order_map.end())
                {
                    if(it->second != 0)
                    {
                        break;
                    }
                    it++;
                }
            }
            
            s[index[i]] = it->first;
            it->second--;

        }
        return s;
    }
};
