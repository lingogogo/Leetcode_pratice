class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // We use the s1 to our goal string
        int n = s1.size();

        int the_wrong_count = 0;
        int arr_char1[26] = {0};
        int arr_char2[26] = {0};
        for(int i = 0; i < n; i++)
        {
            arr_char1[s1[i] - 'a']++;
            arr_char2[s2[i] - 'a']++;
            if(s2[i] != s1[i]){
                the_wrong_count++;
            }
            if(the_wrong_count >2) return false;
        }

        for(int i = 0; i < 26; i++)
        {
            if(arr_char1[i] != arr_char2[i]) return false;
        }
        return true;
    }
};
