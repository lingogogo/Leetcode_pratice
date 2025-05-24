class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> word_contains;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                if(words[i][j] == x)
                {
                    word_contains.push_back(i);
                    break;
                }
            }
        }
        return word_contains; 
    }
};
